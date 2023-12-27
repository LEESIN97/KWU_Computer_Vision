#include "circleHough.h"
#include "edge.h"

int KCircleHough::Init(void* pInfo)
{
    _oInfo = *(KCIRCLEHOUGH_INFO*)pInfo;

    //create voting table
    _lllVotes.resize(_oInfo.nNumGridCy);
    for(auto& itemY : _lllVotes)
    {
        itemY.resize(_oInfo.nNumGridCx);
        for(auto& itemX : itemY)
            itemX.resize(_oInfo.nNumGridR);
    }

    //equal ratio for quantization of center positon and radius
    _dSx = (double)(_oInfo.nRight - _oInfo.nLeft) / (double)(_oInfo.nNumGridCx-1); //Cx = nLeft  + k*_dSx
    _dSy = (double)(_oInfo.nBottom- _oInfo.nTop)  / (double)(_oInfo.nNumGridCy-1); //Cy = nTop   + k*_dSy
    _dSr = (double)(_oInfo.nMaxR  - _oInfo.nMinR) / (double)(_oInfo.nNumGridR -1); //R  = nMinR  + k*_dSr

    return 1;
}

void* KCircleHough::Run(void* pEdge, void* pFrom,void* pTo,void* p4, void* p5)
{
    int			nGridCx,nGridCy,nGridR;
    double		dRadius;
    double		dAngle;
    KPoint		ptCen;
    KEdge* 		opEdge = (KEdge*)pEdge;
    KCircle*	ccpFrom = (KCircle*)pFrom;
    KCircle*	ccpTo   = (KCircle*)pTo;

    //reset the voting table
    _lllVotes.resize(_oInfo.nNumGridCy);
    for(auto& itemY : _lllVotes)
    {
        itemY.resize(_oInfo.nNumGridCx);
        for(auto& itemX : itemY)
            itemX.resize(_oInfo.nNumGridR);
    }

    //Hough Transform
    for(auto& oEdgePxl : *opEdge)
    {
        //check if the edge is in effective region
        if(ccpTo && !ccpTo->InCircle((double)oEdgePxl.u,(double)oEdgePxl.v))
            continue;
        if(ccpFrom && ccpFrom->InCircle((double)oEdgePxl.u,(double)oEdgePxl.v))
            continue;

        //votes for radius
        nGridR 	= 1;
        dRadius = (double)_oInfo.nMinR;
        do{
            //compute circle centers for voting
            dAngle 	  =	_RADIAN(oEdgePxl.wAng);
            if(_oInfo.nDirEdge == _OUTWARD_EDGE)
            {
                ptCen._dX = oEdgePxl.u - dRadius*cos(dAngle);
                ptCen._dY = oEdgePxl.v - dRadius*sin(dAngle);
            }
            else //_INWARD_EDGE
            {
                ptCen._dX = oEdgePxl.u + dRadius*cos(dAngle);
                ptCen._dY = oEdgePxl.v + dRadius*sin(dAngle);
            }

            //compute grid coordinates
            nGridCx	  = (int)( (ptCen._dX - (double)_oInfo.nLeft)/_dSx );
            if(nGridCx < 2 || nGridCx > _oInfo.nNumGridCx-3)
                continue;
            nGridCy	  = (int)( (ptCen._dY - (double)_oInfo.nTop)/_dSy );
            if(nGridCy < 2 || nGridCy > _oInfo.nNumGridCy-3)
                continue;

            //votes to avoid edge noises
            for(int i=-2; i<3; i++)
                for(int j=-2; j<3; j++)
                {
                    _lllVotes[nGridCy+i][nGridCx+j][nGridR-1] += 0.7;
                    _lllVotes[nGridCy+i][nGridCx+j][nGridR]   += 0.7;
                    _lllVotes[nGridCy+i][nGridCx+j][nGridR+1] += 0.7;
                }
            _lllVotes[nGridCy][nGridCx][nGridR] += 0.3;

            //increment
            dRadius += _dSr;

        }while(++nGridR < _oInfo.nNumGridR-1);
    }


    //-------------------------------------------------------------------
    int	nGmax=0;
    for(int i=0; i<_oInfo.nNumGridCy; i++)
    {
        for(int j=0; j<_oInfo.nNumGridCx; j++)
        {
            for(int k=0; k<_oInfo.nNumGridR; k++)
                if(_lllVotes[i][j][k] > nGmax)
                {
                    nGmax 	= (int)(_lllVotes[i][j][k]);
                    nGridCx	= j;
                    nGridCy	= i;
                    nGridR	= k;
                }
        }
    }

    int nThresh = (_oInfo.nThreshVote == 0 ? _PI*(_oInfo.nMinR + nGridR*_dSr)*0.5 : _oInfo.nThreshVote);
    if(nGmax < nThresh)
        return nullptr;

    //select peaks
    for(int i=1, ii=_oInfo.nNumGridCy-1; ii; i++,ii--)
    {
        for(int j=1, jj=_oInfo.nNumGridCx-1; jj; j++,jj--)
        {
            for(int k=1, kk=_oInfo.nNumGridR-1; kk; k++,kk--)
                if(_lllVotes[i][j][k] > _oInfo.nThreshVote)
                {
                    if(_lllVotes[i][j][k]/nGmax > 0.5)
                    {
                        _lDetected.push_back(new KCircle(_oInfo.nLeft+j*_dSx,_oInfo.nTop+i*_dSy,_oInfo.nMinR + k*_dSr));
                        _lVote.push_back(_lllVotes[i][j][k]);
                    }
                }
        }
    }

    //merge peaks
    int	   nRef, nTar;
    KCircle ccRef;

    for(int i=0; i<_lVote.size()-1; i++)
        for(int j=i+1; j<_lVote.size(); j++)
        {
            if(_lDetected[i]->_dRadius > _lDetected[j]->_dRadius)
            {
                nRef = i; nTar = j;
            }
            else{
                nRef = j; nTar = i;
            }
            ccRef = *_lDetected[nRef];
            ccRef._dRadius *= 0.5;


            if(ccRef.InCircle(_lDetected[nTar]->Center()))
            {
                if(_lVote[i] > _lVote[j])
                {
                    _lVote.erase(_lVote.begin() + j);
                    _lDetected.erase(_lDetected.begin() + j--);
                }
                else
                {
                    _lVote.erase(_lVote.begin() + i);
                    _lDetected.erase(_lDetected.begin() + i--);
                    break;
                }
            }
        }

    //return
    if (_lDetected.empty()) {
        return nullptr;
    } else {
        return new vector<KCircle*>(_lDetected);
    }
    //-------------------------------------------------------------------
    /*
    //select peaks
    int	nGmax=0;
    for(int i=0; i<_oInfo.nNumGridCy; i++)
    {
        for(int j=0; j<_oInfo.nNumGridCx; j++)
        {
            for(int k=0; k<_oInfo.nNumGridR; k++)
                if(_lllVotes[i][j][k] > nGmax)
                {
                    nGmax 	= (int)(_lllVotes[i][j][k]);
                    nGridCx	= j;
                    nGridCy	= i;
                    nGridR	= k;
                }
        }
    }

    int nThresh = (_oInfo.nThreshVote == 0 ? _PI*(_oInfo.nMinR + nGridR*_dSr)*0.5 : _oInfo.nThreshVote);
    if(nGmax < nThresh)
        return 0;


    //중심 및 반지름의 그리드 값으로 부터 실제 픽셀 단위로 환산하여 반환한다
    _oDetected.Create(_oInfo.nLeft+nGridCx*_dSx,_oInfo.nTop+nGridCy*_dSy,_oInfo.nMinR + nGridR*_dSr);
    return (void*)(&_oDetected);
*/
}

//---------------------------------------------------------------------------

/*
void* KCircleHough::RunMulti(void* pEdge, void* pFrom,void* pTo,void* p4,void* p5)
{
	int			nGridCx,nGridCy,nGridR;
	double		dRadius;
	double		dAngle;
	KPoint		ptCen;
	KEdge* 		opEdge = (KEdge*)pEdge;
	KCircle*	ccpFrom = (KCircle*)pFrom;
	KCircle*	ccpTo   = (KCircle*)pTo;

	//reset the voting table
	for(int i=0; i<_oInfo.nNumGridCy; i++)
		for(int j=0; j<_oInfo.nNumGridCx; j++)
			memset(_arVotes[i][j],0,_oInfo.nNumGridR*sizeof(double));


    //Hough Transform
    for(auto& oEdgePxl : *opEdge)
	{
		//check if the edge is in effective region
        if(ccpTo && !ccpTo->InCircle((double)oEdgePxl.u,(double)oEdgePxl.v))
			continue;
        if(ccpFrom && ccpFrom->InCircle((double)oEdgePxl.u,(double)oEdgePxl.v))
			continue;

		//votes for radius
		nGridR 	= 1;
		dRadius = (double)_oInfo.nMinR;
		do{
			//compute circle centers for voting
            dAngle 	  =	_RADIAN(oEdgePxl.wAng);
        
	 		if(_oInfo.nDirEdge == _OUTWARD_EDGE)
	 		{
                ptCen._dX = oEdgePxl.u - dRadius*cos(dAngle);
                ptCen._dY = oEdgePxl.v - dRadius*sin(dAngle);
	  		}
	  		else //_INWARD_EDGE
	  		{
                ptCen._dX = oEdgePxl.u + dRadius*cos(dAngle);
                ptCen._dY = oEdgePxl.v + dRadius*sin(dAngle);
	   	   	}     

			//compute grid coordinates
			nGridCx	  = (int)( (ptCen._dX - (double)_oInfo.nLeft)/_dSx );
			if(nGridCx < 2 || nGridCx > _oInfo.nNumGridCx-3)
				continue;
			nGridCy	  = (int)( (ptCen._dY - (double)_oInfo.nTop)/_dSy );
			if(nGridCy < 2 || nGridCy > _oInfo.nNumGridCy-3)
				continue;          

			//votes to avoid edge noises
			for(int i=-2; i<3; i++)
				for(int j=-2; j<3; j++)
				{
					_arVotes[nGridCy+i][nGridCx+j][nGridR-1] += 0.7;
					_arVotes[nGridCy+i][nGridCx+j][nGridR]   += 0.7;
					_arVotes[nGridCy+i][nGridCx+j][nGridR+1] += 0.7;
				}
			_arVotes[nGridCy][nGridCx][nGridR] += 0.3;

			//increment
			dRadius += _dSr;

		}while(++nGridR < _oInfo.nNumGridR-1);
	}

	//obtain the global max
	double dGmax = 0.0;
	for(int i=1; i<_oInfo.nNumGridCy-1; i++)
		for(int j=1; j<_oInfo.nNumGridCx-1; j++)
			for(int k=1; k<_oInfo.nNumGridR-1; k++)
				 dGmax = ( _arVotes[i][j][k] > dGmax ? _arVotes[i][j][k] : dGmax );

	if(dGmax < _oInfo.nThreshVote)
		return 0;

	//select peaks
	_lDetected.RemoveAll();
    _lVote.RemoveAll();
	for(int i=1, ii=_oInfo.nNumGridCy-1; ii; i++,ii--)
    {
		for(int j=1, jj=_oInfo.nNumGridCx-1; jj; j++,jj--)
        {           	
			for(int k=1, kk=_oInfo.nNumGridR-1; kk; k++,kk--)
				if(_arVotes[i][j][k] > _oInfo.nThreshVote)
				{       	            
				   	if(_arVotes[i][j][k]/dGmax > 0.5)
				   	{
						_lDetected.Add(new KCircle(_oInfo.nLeft+j*_dSx,_oInfo.nTop+i*_dSy,_oInfo.nMinR + k*_dSr));
						_lVote.Add(_arVotes[i][j][k]);
				   	}
				}
        }
    }
  
	//merge peaks
	int	   nRef, nTar;
	KCircle ccRef;

	for(int i=0; i<_lVote.Count()-1; i++)
		for(int j=i+1; j<_lVote.Count(); j++)
		{
			if(_lDetected[i]->_dRadius > _lDetected[j]->_dRadius)
			{
				nRef = i; nTar = j;
			}
			else{
				nRef = j; nTar = i;
			}
			ccRef = *_lDetected[nRef];
			ccRef._dRadius *= 0.5;


			if(ccRef.InCircle(_lDetected[nTar]->Center()))
			{
				if(_lVote[i] > _lVote[j])
				{
					_lVote.RemoveAt(j);
					_lDetected.RemoveAt(j--);
				}
				else
				{
					_lVote.RemoveAt(i);
					_lDetected.RemoveAt(i--);
					break;
				}
			}
		}
 
	//return
	return (void*)(_lDetected.Count() ? &_lDetected : 0);
}
*/
//---------------------------------------------------------------------------

