/*
 * H264FramedLiveSource.hh
 *
 * Description: 添加RTSP直播
 *  Created on: Jan 21, 2015
 *      Author: sudoz
 */

#ifndef H264FRAMEDLIVESOURCE_HH_
#define H264FRAMEDLIVESOURCE_HH_

#include "FramedSource.hh"

class H264FramedLiveSource : public FramedSource
{
public:
	static H264FramedLiveSource* createNew(UsageEnvironment& env,
			char const* fileName,
			unsigned preferredFrameSize = 0,
			unsigned playTimePerFrame = 0);

protected:
	H264FramedLiveSource(UsageEnvironment& env,
			char const* fileName,
			unsigned preferredFrameSize,
			unsigned playTimePerFrame);

	// 只能被createNew()调用
	~H264FramedLiveSource();

private:
	// 重定义doGetNextFrame()
	virtual void doGetNextFrame();
	int TransportData(unsigned char* to, unsigned maxSize);

protected:
	FILE* fp;
};



#endif /* H264FRAMEDLIVESOURCE_HH_ */
