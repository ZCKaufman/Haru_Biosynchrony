#ifndef _ROS_SERVICE_WeatherInfoByCoordinates_h
#define _ROS_SERVICE_WeatherInfoByCoordinates_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/WeatherInfo.h"

namespace strawberry_ros_msgs
{

static const char WEATHERINFOBYCOORDINATES[] = "strawberry_ros_msgs/WeatherInfoByCoordinates";

  class WeatherInfoByCoordinatesRequest : public ros::Msg
  {
    public:
      typedef float _latitude_type;
      _latitude_type latitude;
      typedef float _longitude_type;
      _longitude_type longitude;

    WeatherInfoByCoordinatesRequest():
      latitude(0),
      longitude(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_latitude;
      u_latitude.real = this->latitude;
      *(outbuffer + offset + 0) = (u_latitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_latitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_latitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_latitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->latitude);
      union {
        float real;
        uint32_t base;
      } u_longitude;
      u_longitude.real = this->longitude;
      *(outbuffer + offset + 0) = (u_longitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_longitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_longitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_longitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->longitude);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_latitude;
      u_latitude.base = 0;
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_latitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->latitude = u_latitude.real;
      offset += sizeof(this->latitude);
      union {
        float real;
        uint32_t base;
      } u_longitude;
      u_longitude.base = 0;
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_longitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->longitude = u_longitude.real;
      offset += sizeof(this->longitude);
     return offset;
    }

    virtual const char * getType() override { return WEATHERINFOBYCOORDINATES; };
    virtual const char * getMD5() override { return "9aeb2245d9611f300beeb62a0151d3f3"; };

  };

  class WeatherInfoByCoordinatesResponse : public ros::Msg
  {
    public:
      typedef strawberry_ros_msgs::WeatherInfo _weather_info_type;
      _weather_info_type weather_info;

    WeatherInfoByCoordinatesResponse():
      weather_info()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->weather_info.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->weather_info.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return WEATHERINFOBYCOORDINATES; };
    virtual const char * getMD5() override { return "722e5ef859523f4774eb01b2598f65e5"; };

  };

  class WeatherInfoByCoordinates {
    public:
    typedef WeatherInfoByCoordinatesRequest Request;
    typedef WeatherInfoByCoordinatesResponse Response;
  };

}
#endif
