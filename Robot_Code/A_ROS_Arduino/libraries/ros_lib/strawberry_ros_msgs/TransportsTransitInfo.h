#ifndef _ROS_SERVICE_TransportsTransitInfo_h
#define _ROS_SERVICE_TransportsTransitInfo_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/TransportsRoute.h"

namespace strawberry_ros_msgs
{

static const char TRANSPORTSTRANSITINFO[] = "strawberry_ros_msgs/TransportsTransitInfo";

  class TransportsTransitInfoRequest : public ros::Msg
  {
    public:
      typedef const char* _origin_type;
      _origin_type origin;
      typedef const char* _destination_type;
      _destination_type destination;
      typedef const char* _departure_time_type;
      _departure_time_type departure_time;
      typedef const char* _transit_mode_type;
      _transit_mode_type transit_mode;

    TransportsTransitInfoRequest():
      origin(""),
      destination(""),
      departure_time(""),
      transit_mode("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_origin = strlen(this->origin);
      varToArr(outbuffer + offset, length_origin);
      offset += 4;
      memcpy(outbuffer + offset, this->origin, length_origin);
      offset += length_origin;
      uint32_t length_destination = strlen(this->destination);
      varToArr(outbuffer + offset, length_destination);
      offset += 4;
      memcpy(outbuffer + offset, this->destination, length_destination);
      offset += length_destination;
      uint32_t length_departure_time = strlen(this->departure_time);
      varToArr(outbuffer + offset, length_departure_time);
      offset += 4;
      memcpy(outbuffer + offset, this->departure_time, length_departure_time);
      offset += length_departure_time;
      uint32_t length_transit_mode = strlen(this->transit_mode);
      varToArr(outbuffer + offset, length_transit_mode);
      offset += 4;
      memcpy(outbuffer + offset, this->transit_mode, length_transit_mode);
      offset += length_transit_mode;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_origin;
      arrToVar(length_origin, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_origin; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_origin-1]=0;
      this->origin = (char *)(inbuffer + offset-1);
      offset += length_origin;
      uint32_t length_destination;
      arrToVar(length_destination, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_destination; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_destination-1]=0;
      this->destination = (char *)(inbuffer + offset-1);
      offset += length_destination;
      uint32_t length_departure_time;
      arrToVar(length_departure_time, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_departure_time; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_departure_time-1]=0;
      this->departure_time = (char *)(inbuffer + offset-1);
      offset += length_departure_time;
      uint32_t length_transit_mode;
      arrToVar(length_transit_mode, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_transit_mode; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_transit_mode-1]=0;
      this->transit_mode = (char *)(inbuffer + offset-1);
      offset += length_transit_mode;
     return offset;
    }

    virtual const char * getType() override { return TRANSPORTSTRANSITINFO; };
    virtual const char * getMD5() override { return "70919e004a34509932cb4956bb25d81b"; };

  };

  class TransportsTransitInfoResponse : public ros::Msg
  {
    public:
      typedef strawberry_ros_msgs::TransportsRoute _transit_info_type;
      _transit_info_type transit_info;
      typedef bool _success_type;
      _success_type success;

    TransportsTransitInfoResponse():
      transit_info(),
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->transit_info.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->transit_info.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return TRANSPORTSTRANSITINFO; };
    virtual const char * getMD5() override { return "28aa8118ace760dbe4cff14eaadf18f3"; };

  };

  class TransportsTransitInfo {
    public:
    typedef TransportsTransitInfoRequest Request;
    typedef TransportsTransitInfoResponse Response;
  };

}
#endif
