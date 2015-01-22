/*
 * H264LiveVideoServerMediaSubssion.cpp
 *
 *  Created on: Jan 21, 2015
 *      Author: sudoz
 */

#include "H264LiveVideoServerMediaSubssion.hh"
#include "H264FramedLiveSource.hh"
#include "H264VideoStreamFramer.hh"


H264LiveVideoServerMediaSubssion* H264LiveVideoServerMediaSubssion::createNew(
		UsageEnvironment& env,
		char const* fileName,
		Boolean reuseFirstSource)
{
	return new H264LiveVideoServerMediaSubssion(env, fileName, reuseFirstSource);
}

H264LiveVideoServerMediaSubssion::H264LiveVideoServerMediaSubssion(UsageEnvironment & env,
		char const* fileName, Boolean reuseFirstSource)
: H264VideoFileServerMediaSubsession(env, fileName, reuseFirstSource)
{
	strcpy(fFileName, fileName);
}

H264LiveVideoServerMediaSubssion::~H264LiveVideoServerMediaSubssion()
{
}

FramedSource* H264LiveVideoServerMediaSubssion::createNewStreamSource( unsigned clientSessionId, unsigned& estBitrate )
{
    /* Remain to do : assign estBitrate */
    estBitrate = 1000; // kbps, estimate

    // Create the video source:
    H264FramedLiveSource* liveSource = H264FramedLiveSource::createNew(envir(), fFileName);
    if (liveSource == NULL)
    {
        return NULL;
    }

    // Create a framer for the Video Elementary Stream:
    return H264VideoStreamFramer::createNew(envir(), liveSource);
}
