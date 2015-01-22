/*
 * H264FramedLiveSource.cpp
 *
 * Description: 添加RTSP直播
 *  Created on: Jan 21, 2015
 *      Author: sudoz
 */

#include "H264FramedLiveSource.hh"

/*
 * 构造函数
 */
H264FramedLiveSource::H264FramedLiveSource(UsageEnvironment& env,
		char const* fileName,
		unsigned preferredFrameSize,
		unsigned playTimePerFrame) : FramedSource(env)
{
	fp = fopen(fileName, "rb");	// 可读写打开文件
}

/*
 * 析构函数
 */
H264FramedLiveSource::~H264FramedLiveSource()
{
	fclose(fp);
}

/*
 * 创建流
 */
H264FramedLiveSource* H264FramedLiveSource::createNew(UsageEnvironment& env,
		char const* fileName,
		unsigned preferredFrameSize,
		unsigned playTimePerFrame)
{
	H264FramedLiveSource* newSource = new H264FramedLiveSource(env, fileName, preferredFrameSize, playTimePerFrame);

	return newSource;
}

long fileSize(FILE* stream)
{
	long curpos, length;
	curpos = ftell(stream);
	fseek(stream, 0L, SEEK_END);
	length = ftell(stream);
	fseek(stream, curpos, SEEK_SET);

	return length;
}

/**
 * 重写父类虚函数doGetNextFrame()
 */
void H264FramedLiveSource::doGetNextFrame()
{
	int sz = fileSize(fp);

	if (sz > fMaxSize) {
		// fFrameSize表示实际发送的内容字节数
		fFrameSize = fread(fTo, 1, fMaxSize, fp);
	} else {
		fFrameSize = fread(fTo, 1, sz, fp);
		fseek(fp, 0, SEEK_SET);
	}

	// 延迟0秒后执行afterGetting()
	nextTask() = envir().taskScheduler().scheduleDelayedTask(0, (TaskFunc*)FramedSource::afterGetting, this);

	return;
}




