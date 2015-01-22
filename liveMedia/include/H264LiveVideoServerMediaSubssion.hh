/*
 * H264LiveVideoServerMediaSubssion.hh
 *
 *  Created on: Jan 21, 2015
 *      Author: sudoz
 */

#ifndef H264LIVEVIDEOSERVERMEDIASUBSSION_HH_
#define H264LIVEVIDEOSERVERMEDIASUBSSION_HH_


#include "H264VideoFileServerMediaSubsession.hh"


class H264LiveVideoServerMediaSubssion : public H264VideoFileServerMediaSubsession
{
public:
	static H264LiveVideoServerMediaSubssion* createNew(UsageEnvironment& env,
			char const* fileName,
			Boolean reuseFirstSource);

protected:
	H264LiveVideoServerMediaSubssion(UsageEnvironment& env,
			char const* fileName,
			Boolean reuseFirstSource);
	~H264LiveVideoServerMediaSubssion();

protected:
	FramedSource* createNewStreamSource(unsigned clientSessionId, unsigned& estBitrate);

public:
	char fFileName[100];

};


#endif /* H264LIVEVIDEOSERVERMEDIASUBSSION_HH_ */
