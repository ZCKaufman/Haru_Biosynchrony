#ifndef _ROS_strawberry_ros_msgs_TransportsRoute_h
#define _ROS_strawberry_ros_msgs_TransportsRoute_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/TransportsStep.h"
#include "sensor_msgs/CompressedImage.h"

namespace strawberry_ros_msgs
{

  class TransportsRoute : public ros::Msg
  {
    public:
      uint32_t steps_length;
      typedef strawberry_ros_msgs::TransportsStep _steps_type;
      _steps_type st_steps;
      _steps_type * steps;
      typedef const char* _summary_type;
      _summary_type summary;
      typedef const char* _distance_type;
      _distance_type distance;
      typedef const char* _duration_type;
      _duration_type duration;
      typedef const char* _departure_time_type;
      _departure_time_type departure_time;
      typedef const char* _arrival_time_type;
      _arrival_time_type arrival_time;
      typedef const char* _start_address_type;
      _start_address_type start_address;
      typedef const char* _end_address_type;
      _end_address_type end_address;
      typedef sensor_msgs::CompressedImage _image_type;
      _image_type image;
      typedef const char* _desired_transit_mode_type;
      _desired_transit_mode_type desired_transit_mode;

    TransportsRoute():
      steps_length(0), st_steps(), steps(nullptr),
      summary(""),
      distance(""),
      duration(""),
      departure_time(""),
      arrival_time(""),
      start_address(""),
      end_address(""),
      image(),
      desired_transit_mode("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->steps_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->steps_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->steps_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->steps_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steps_length);
      for( uint32_t i = 0; i < steps_length; i++){
      offset += this->steps[i].serialize(outbuffer + offset);
      }
      uint32_t length_summary = strlen(this->summary);
      varToArr(outbuffer + offset, length_summary);
      offset += 4;
      memcpy(outbuffer + offset, this->summary, length_summary);
      offset += length_summary;
      uint32_t length_distance = strlen(this->distance);
      varToArr(outbuffer + offset, length_distance);
      offset += 4;
      memcpy(outbuffer + offset, this->distance, length_distance);
      offset += length_distance;
      uint32_t length_duration = strlen(this->duration);
      varToArr(outbuffer + offset, length_duration);
      offset += 4;
      memcpy(outbuffer + offset, this->duration, length_duration);
      offset += length_duration;
      uint32_t length_departure_time = strlen(this->departure_time);
      varToArr(outbuffer + offset, length_departure_time);
      offset += 4;
      memcpy(outbuffer + offset, this->departure_time, length_departure_time);
      offset += length_departure_time;
      uint32_t length_arrival_time = strlen(this->arrival_time);
      varToArr(outbuffer + offset, length_arrival_time);
      offset += 4;
      memcpy(outbuffer + offset, this->arrival_time, length_arrival_time);
      offset += length_arrival_time;
      uint32_t length_start_address = strlen(this->start_address);
      varToArr(outbuffer + offset, length_start_address);
      offset += 4;
      memcpy(outbuffer + offset, this->start_address, length_start_address);
      offset += length_start_address;
      uint32_t length_end_address = strlen(this->end_address);
      varToArr(outbuffer + offset, length_end_address);
      offset += 4;
      memcpy(outbuffer + offset, this->end_address, length_end_address);
      offset += length_end_address;
      offset += this->image.serialize(outbuffer + offset);
      uint32_t length_desired_transit_mode = strlen(this->desired_transit_mode);
      varToArr(outbuffer + offset, length_desired_transit_mode);
      offset += 4;
      memcpy(outbuffer + offset, this->desired_transit_mode, length_desired_transit_mode);
      offset += length_desired_transit_mode;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t steps_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      steps_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      steps_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      steps_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->steps_length);
      if(steps_lengthT > steps_length)
        this->steps = (strawberry_ros_msgs::TransportsStep*)realloc(this->steps, steps_lengthT * sizeof(strawberry_ros_msgs::TransportsStep));
      steps_length = steps_lengthT;
      for( uint32_t i = 0; i < steps_length; i++){
      offset += this->st_steps.deserialize(inbuffer + offset);
        memcpy( &(this->steps[i]), &(this->st_steps), sizeof(strawberry_ros_msgs::TransportsStep));
      }
      uint32_t length_summary;
      arrToVar(length_summary, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_summary; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_summary-1]=0;
      this->summary = (char *)(inbuffer + offset-1);
      offset += length_summary;
      uint32_t length_distance;
      arrToVar(length_distance, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_distance; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_distance-1]=0;
      this->distance = (char *)(inbuffer + offset-1);
      offset += length_distance;
      uint32_t length_duration;
      arrToVar(length_duration, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_duration; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_duration-1]=0;
      this->duration = (char *)(inbuffer + offset-1);
      offset += length_duration;
      uint32_t length_departure_time;
      arrToVar(length_departure_time, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_departure_time; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_departure_time-1]=0;
      this->departure_time = (char *)(inbuffer + offset-1);
      offset += length_departure_time;
      uint32_t length_arrival_time;
      arrToVar(length_arrival_time, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_arrival_time; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_arrival_time-1]=0;
      this->arrival_time = (char *)(inbuffer + offset-1);
      offset += length_arrival_time;
      uint32_t length_start_address;
      arrToVar(length_start_address, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_start_address; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_start_address-1]=0;
      this->start_address = (char *)(inbuffer + offset-1);
      offset += length_start_address;
      uint32_t length_end_address;
      arrToVar(length_end_address, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_end_address; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_end_address-1]=0;
      this->end_address = (char *)(inbuffer + offset-1);
      offset += length_end_address;
      offset += this->image.deserialize(inbuffer + offset);
      uint32_t length_desired_transit_mode;
      arrToVar(length_desired_transit_mode, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_desired_transit_mode; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_desired_transit_mode-1]=0;
      this->desired_transit_mode = (char *)(inbuffer + offset-1);
      offset += length_desired_transit_mode;
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/TransportsRoute"; };
    virtual const char * getMD5() override { return "ac87cff9411e963ca36557a175ec7f02"; };

  };

}
#endif
