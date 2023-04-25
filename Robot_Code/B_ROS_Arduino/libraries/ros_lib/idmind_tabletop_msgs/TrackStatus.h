#ifndef _ROS_idmind_tabletop_msgs_TrackStatus_h
#define _ROS_idmind_tabletop_msgs_TrackStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class TrackStatus : public ros::Msg
  {
    public:
      typedef bool _tracking_type;
      _tracking_type tracking;
      typedef bool _tracking_using_vel_type;
      _tracking_using_vel_type tracking_using_vel;
      typedef const char* _tracked_frame_type;
      _tracked_frame_type tracked_frame;

    TrackStatus():
      tracking(0),
      tracking_using_vel(0),
      tracked_frame("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_tracking;
      u_tracking.real = this->tracking;
      *(outbuffer + offset + 0) = (u_tracking.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tracking);
      union {
        bool real;
        uint8_t base;
      } u_tracking_using_vel;
      u_tracking_using_vel.real = this->tracking_using_vel;
      *(outbuffer + offset + 0) = (u_tracking_using_vel.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->tracking_using_vel);
      uint32_t length_tracked_frame = strlen(this->tracked_frame);
      varToArr(outbuffer + offset, length_tracked_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->tracked_frame, length_tracked_frame);
      offset += length_tracked_frame;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_tracking;
      u_tracking.base = 0;
      u_tracking.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->tracking = u_tracking.real;
      offset += sizeof(this->tracking);
      union {
        bool real;
        uint8_t base;
      } u_tracking_using_vel;
      u_tracking_using_vel.base = 0;
      u_tracking_using_vel.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->tracking_using_vel = u_tracking_using_vel.real;
      offset += sizeof(this->tracking_using_vel);
      uint32_t length_tracked_frame;
      arrToVar(length_tracked_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_tracked_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_tracked_frame-1]=0;
      this->tracked_frame = (char *)(inbuffer + offset-1);
      offset += length_tracked_frame;
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/TrackStatus"; };
    virtual const char * getMD5() override { return "79e1337f7a49c2d2cb08d539e5ff6f2f"; };

  };

}
#endif
