#ifndef _ROS_strawberry_ros_msgs_TransportsStep_h
#define _ROS_strawberry_ros_msgs_TransportsStep_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/TransportsTransitDetails.h"

namespace strawberry_ros_msgs
{

  class TransportsStep : public ros::Msg
  {
    public:
      typedef const char* _distance_type;
      _distance_type distance;
      typedef const char* _duration_type;
      _duration_type duration;
      typedef const char* _start_location_type;
      _start_location_type start_location;
      typedef const char* _end_location_type;
      _end_location_type end_location;
      typedef const char* _travel_mode_type;
      _travel_mode_type travel_mode;
      typedef strawberry_ros_msgs::TransportsTransitDetails _transit_details_type;
      _transit_details_type transit_details;

    TransportsStep():
      distance(""),
      duration(""),
      start_location(""),
      end_location(""),
      travel_mode(""),
      transit_details()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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
      uint32_t length_start_location = strlen(this->start_location);
      varToArr(outbuffer + offset, length_start_location);
      offset += 4;
      memcpy(outbuffer + offset, this->start_location, length_start_location);
      offset += length_start_location;
      uint32_t length_end_location = strlen(this->end_location);
      varToArr(outbuffer + offset, length_end_location);
      offset += 4;
      memcpy(outbuffer + offset, this->end_location, length_end_location);
      offset += length_end_location;
      uint32_t length_travel_mode = strlen(this->travel_mode);
      varToArr(outbuffer + offset, length_travel_mode);
      offset += 4;
      memcpy(outbuffer + offset, this->travel_mode, length_travel_mode);
      offset += length_travel_mode;
      offset += this->transit_details.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
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
      uint32_t length_start_location;
      arrToVar(length_start_location, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_start_location; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_start_location-1]=0;
      this->start_location = (char *)(inbuffer + offset-1);
      offset += length_start_location;
      uint32_t length_end_location;
      arrToVar(length_end_location, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_end_location; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_end_location-1]=0;
      this->end_location = (char *)(inbuffer + offset-1);
      offset += length_end_location;
      uint32_t length_travel_mode;
      arrToVar(length_travel_mode, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_travel_mode; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_travel_mode-1]=0;
      this->travel_mode = (char *)(inbuffer + offset-1);
      offset += length_travel_mode;
      offset += this->transit_details.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/TransportsStep"; };
    virtual const char * getMD5() override { return "2af8e10cce1ae0ded62dbff3c9f408a6"; };

  };

}
#endif
