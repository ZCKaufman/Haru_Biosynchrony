#ifndef _ROS_SERVICE_WeatherInfoByPlacename_h
#define _ROS_SERVICE_WeatherInfoByPlacename_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/WeatherInfo.h"

namespace strawberry_ros_msgs
{

static const char WEATHERINFOBYPLACENAME[] = "strawberry_ros_msgs/WeatherInfoByPlacename";

  class WeatherInfoByPlacenameRequest : public ros::Msg
  {
    public:
      typedef const char* _placename_type;
      _placename_type placename;

    WeatherInfoByPlacenameRequest():
      placename("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_placename = strlen(this->placename);
      varToArr(outbuffer + offset, length_placename);
      offset += 4;
      memcpy(outbuffer + offset, this->placename, length_placename);
      offset += length_placename;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_placename;
      arrToVar(length_placename, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_placename; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_placename-1]=0;
      this->placename = (char *)(inbuffer + offset-1);
      offset += length_placename;
     return offset;
    }

    virtual const char * getType() override { return WEATHERINFOBYPLACENAME; };
    virtual const char * getMD5() override { return "6354ccbaa6685a5d8fce1707763b73ea"; };

  };

  class WeatherInfoByPlacenameResponse : public ros::Msg
  {
    public:
      typedef strawberry_ros_msgs::WeatherInfo _weather_info_type;
      _weather_info_type weather_info;

    WeatherInfoByPlacenameResponse():
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

    virtual const char * getType() override { return WEATHERINFOBYPLACENAME; };
    virtual const char * getMD5() override { return "722e5ef859523f4774eb01b2598f65e5"; };

  };

  class WeatherInfoByPlacename {
    public:
    typedef WeatherInfoByPlacenameRequest Request;
    typedef WeatherInfoByPlacenameResponse Response;
  };

}
#endif
