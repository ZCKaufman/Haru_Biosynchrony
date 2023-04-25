#ifndef _ROS_strawberry_ros_msgs_WeatherInfo_h
#define _ROS_strawberry_ros_msgs_WeatherInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/WeatherForecastHour.h"

namespace strawberry_ros_msgs
{

  class WeatherInfo : public ros::Msg
  {
    public:
      typedef const char* _weather_main_type;
      _weather_main_type weather_main;
      typedef const char* _weather_description_type;
      _weather_description_type weather_description;
      typedef float _current_temperature_type;
      _current_temperature_type current_temperature;
      typedef float _current_temperature_feeling_type;
      _current_temperature_feeling_type current_temperature_feeling;
      typedef const char* _icon_type;
      _icon_type icon;
      uint32_t hourly_forecast_length;
      typedef strawberry_ros_msgs::WeatherForecastHour _hourly_forecast_type;
      _hourly_forecast_type st_hourly_forecast;
      _hourly_forecast_type * hourly_forecast;

    WeatherInfo():
      weather_main(""),
      weather_description(""),
      current_temperature(0),
      current_temperature_feeling(0),
      icon(""),
      hourly_forecast_length(0), st_hourly_forecast(), hourly_forecast(nullptr)
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
      union {
        float real;
        uint32_t base;
      } u_current_temperature;
      u_current_temperature.real = this->current_temperature;
      *(outbuffer + offset + 0) = (u_current_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_temperature);
      union {
        float real;
        uint32_t base;
      } u_current_temperature_feeling;
      u_current_temperature_feeling.real = this->current_temperature_feeling;
      *(outbuffer + offset + 0) = (u_current_temperature_feeling.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_temperature_feeling.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_temperature_feeling.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_temperature_feeling.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_temperature_feeling);
      uint32_t length_icon = strlen(this->icon);
      varToArr(outbuffer + offset, length_icon);
      offset += 4;
      memcpy(outbuffer + offset, this->icon, length_icon);
      offset += length_icon;
      *(outbuffer + offset + 0) = (this->hourly_forecast_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hourly_forecast_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hourly_forecast_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hourly_forecast_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hourly_forecast_length);
      for( uint32_t i = 0; i < hourly_forecast_length; i++){
      offset += this->hourly_forecast[i].serialize(outbuffer + offset);
      }
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
      union {
        float real;
        uint32_t base;
      } u_current_temperature;
      u_current_temperature.base = 0;
      u_current_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_temperature = u_current_temperature.real;
      offset += sizeof(this->current_temperature);
      union {
        float real;
        uint32_t base;
      } u_current_temperature_feeling;
      u_current_temperature_feeling.base = 0;
      u_current_temperature_feeling.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_temperature_feeling.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_temperature_feeling.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_temperature_feeling.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_temperature_feeling = u_current_temperature_feeling.real;
      offset += sizeof(this->current_temperature_feeling);
      uint32_t length_icon;
      arrToVar(length_icon, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_icon; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_icon-1]=0;
      this->icon = (char *)(inbuffer + offset-1);
      offset += length_icon;
      uint32_t hourly_forecast_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      hourly_forecast_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      hourly_forecast_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      hourly_forecast_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->hourly_forecast_length);
      if(hourly_forecast_lengthT > hourly_forecast_length)
        this->hourly_forecast = (strawberry_ros_msgs::WeatherForecastHour*)realloc(this->hourly_forecast, hourly_forecast_lengthT * sizeof(strawberry_ros_msgs::WeatherForecastHour));
      hourly_forecast_length = hourly_forecast_lengthT;
      for( uint32_t i = 0; i < hourly_forecast_length; i++){
      offset += this->st_hourly_forecast.deserialize(inbuffer + offset);
        memcpy( &(this->hourly_forecast[i]), &(this->st_hourly_forecast), sizeof(strawberry_ros_msgs::WeatherForecastHour));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/WeatherInfo"; };
    virtual const char * getMD5() override { return "3e0f042eb8d1c655630641dc87423d96"; };

  };

}
#endif
