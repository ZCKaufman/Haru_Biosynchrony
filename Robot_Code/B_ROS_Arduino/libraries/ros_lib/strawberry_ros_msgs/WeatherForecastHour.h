#ifndef _ROS_strawberry_ros_msgs_WeatherForecastHour_h
#define _ROS_strawberry_ros_msgs_WeatherForecastHour_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class WeatherForecastHour : public ros::Msg
  {
    public:
      typedef const char* _weather_main_type;
      _weather_main_type weather_main;
      typedef const char* _weather_description_type;
      _weather_description_type weather_description;
      typedef const char* _icon_type;
      _icon_type icon;
      typedef float _temperature_type;
      _temperature_type temperature;
      typedef float _temperature_feeling_type;
      _temperature_feeling_type temperature_feeling;

    WeatherForecastHour():
      weather_main(""),
      weather_description(""),
      icon(""),
      temperature(0),
      temperature_feeling(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_weather_main = strlen(this->weather_main);
      varToArr(outbuffer + offset, length_weather_main);
      offset += 4;
      memcpy(outbuffer + offset, this->weather_main, length_weather_main);
      offset += length_weather_main;
      uint32_t length_weather_description = strlen(this->weather_description);
      varToArr(outbuffer + offset, length_weather_description);
      offset += 4;
      memcpy(outbuffer + offset, this->weather_description, length_weather_description);
      offset += length_weather_description;
      uint32_t length_icon = strlen(this->icon);
      varToArr(outbuffer + offset, length_icon);
      offset += 4;
      memcpy(outbuffer + offset, this->icon, length_icon);
      offset += length_icon;
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature);
      union {
        float real;
        uint32_t base;
      } u_temperature_feeling;
      u_temperature_feeling.real = this->temperature_feeling;
      *(outbuffer + offset + 0) = (u_temperature_feeling.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature_feeling.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature_feeling.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature_feeling.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature_feeling);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_weather_main;
      arrToVar(length_weather_main, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_weather_main; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_weather_main-1]=0;
      this->weather_main = (char *)(inbuffer + offset-1);
      offset += length_weather_main;
      uint32_t length_weather_description;
      arrToVar(length_weather_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_weather_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_weather_description-1]=0;
      this->weather_description = (char *)(inbuffer + offset-1);
      offset += length_weather_description;
      uint32_t length_icon;
      arrToVar(length_icon, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_icon; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_icon-1]=0;
      this->icon = (char *)(inbuffer + offset-1);
      offset += length_icon;
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
      union {
        float real;
        uint32_t base;
      } u_temperature_feeling;
      u_temperature_feeling.base = 0;
      u_temperature_feeling.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature_feeling.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature_feeling.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature_feeling.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temperature_feeling = u_temperature_feeling.real;
      offset += sizeof(this->temperature_feeling);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/WeatherForecastHour"; };
    virtual const char * getMD5() override { return "89b635f1184ca294918a44aa38f0e0af"; };

  };

}
#endif
