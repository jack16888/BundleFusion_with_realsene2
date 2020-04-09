#pragma once

/************************************************************************/
/* Prime sense depth camera: Warning this is highly untested atm        */
/************************************************************************/

#include "GlobalAppState.h"

//Only working with OpenNI 2 SDK
#ifdef REALSENSE2OPENNI2

#include "RGBDSensor.h"
#include <OpenNI.h>

#include <vector>
#include <list>

class RealSense2OpenNi2 : public RGBDSensor
{
public:

	//! Constructor; allocates CPU memory and creates handles
	RealSense2OpenNi2();

	//! Destructor; releases allocated ressources
	~RealSense2OpenNi2();

	//! Initializes the sensor
	void createFirstConnected();

	//! Processes the depth data (and color)
	bool processDepth();


	//! Processes the Kinect color data
	bool processColor()
	{
		return true;
	}
	virtual std::string getSensorName() const {
		return std::string("RealSense2 with openNi2");
	}

protected:
	//! reads depth and color from the sensor
	bool readDepthAndColor(float* depthFloat, vec4uc* colorRGBX);


	// to prevent drawing until we have data for both streams
	bool			m_bDepthReceived;
	bool			m_bColorReceived;

	bool			m_bDepthImageIsUpdated;
	bool			m_bDepthImageCameraIsUpdated;
	bool			m_bNormalImageCameraIsUpdated;

	bool			m_kinect4Windows;

	openni::VideoMode			m_depthVideoMode;
	openni::VideoMode			m_colorVideoMode;


	openni::VideoFrameRef		m_depthFrame;
	openni::VideoFrameRef		m_colorFrame;

	openni::Device				m_device;
	openni::VideoStream			m_depthStream;
	openni::VideoStream			m_colorStream;
	openni::VideoStream**		m_streams;

};

#endif