/**********
This library is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the
Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version. (See <http://www.gnu.org/copyleft/lesser.html>.)

This library is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General Public License
along with this library; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
**********/
// Copyright (c) 1996-2015, Live Networks, Inc.  All rights reserved
// A test program that demonstrates how to stream - via unicast RTP
// - various kinds of file on demand, using a built-in RTSP server.
// main program

/*
 * testLiveRTSPServer.cpp
 *
 * Description:测试版main函数
 *  Created on: Jan 21, 2015
 *      Author: sudoz
 */

#include "liveMedia.hh"
#include "BasicUsageEnvironment.hh"
#include "H264LiveVideoServerMediaSubssion.hh"
#include "H264FramedLiveSource.hh"

UsageEnvironment* env;

// To make the second and subsequent client for each stream reuse the same
// input stream as the first client (rather than playing the file from the
// start for each client), change the following "False" to "True":
Boolean reuseFirstSource = False;

// To stream *only* MPEG-1 or 2 video "I" frames
// (e.g., to reduce network bandwidth),
// change the following "False" to "True":
Boolean iFramesOnly = False;

static void announceStream(RTSPServer* rtspServer, ServerMediaSession* sms,
		 char const* streamName, char const* inputFileName);	// fwd

static char newMatroskaDemuxWatchVariable;;
static MatroskaFileServerDemux* matroskaDemux;

static void onMatroskaDemuxCreation(MatroskaFileServerDemux* newDemux, void* /*clientData*/)
{
	matroskaDemux = newDemux;
	newMatroskaDemuxWatchVariable = 1;
}


int main(int argc, char* argv[])
{
	// Begin by setting up our usage environment:
	TaskScheduler* scheduler = BasicTaskScheduler::createNew();
	env = BasicUsageEnvironment::createNew(*scheduler);

}


