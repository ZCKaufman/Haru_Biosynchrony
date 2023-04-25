#ifndef _ROS_strawberry_ros_msgs_LeapMotionHands_h
#define _ROS_strawberry_ros_msgs_LeapMotionHands_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "strawberry_ros_msgs/LeapMotionHand.h"
#include "strawberry_ros_msgs/Gesture.h"

namespace strawberry_ros_msgs
{

  class LeapMotionHands : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef int64_t _frame_id_type;
      _frame_id_type frame_id;
      typedef float _current_frames_per_second_type;
      _current_frames_per_second_type current_frames_per_second;
      uint32_t hands_length;
      typedef strawberry_ros_msgs::LeapMotionHand _hands_type;
      _hands_type st_hands;
      _hands_type * hands;
      uint32_t gestures_length;
      typedef strawberry_ros_msgs::Gesture _gestures_type;
      _gestures_type st_gestures;
      _gestures_type * gestures;

    LeapMotionHands():
      header(),
      frame_id(0),
      current_frames_per_second(0),
      hands_length(0), st_hands(), hands(nullptr),
      gestures_length(0), st_gestures(), gestures(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_frame_id;
      u_frame_id.real = this->frame_id;
      *(outbuffer + offset + 0) = (u_frame_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frame_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frame_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frame_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_frame_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_frame_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_frame_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_frame_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->frame_id);
      union {
        float real;
        uint32_t base;
      } u_current_frames_per_second;
      u_current_frames_per_second.real = this->current_frames_per_second;
      *(outbuffer + offset + 0) = (u_current_frames_per_second.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_current_frames_per_second.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_current_frames_per_second.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_current_frames_per_second.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_frames_per_second);
      *(outbuffer + offset + 0) = (this->hands_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->hands_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->hands_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->hands_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->hands_length);
      for( uint32_t i = 0; i < hands_length; i++){
      offset += this->hands[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->gestures_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gestures_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gestures_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gestures_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gestures_length);
      for( uint32_t i = 0; i < gestures_length; i++){
      offset += this->gestures[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        int64_t real;
        uint64_t base;
      } u_frame_id;
      u_frame_id.base = 0;
      u_frame_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_frame_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_frame_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_frame_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_frame_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_frame_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_frame_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_frame_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->frame_id = u_frame_id.real;
      offset += sizeof(this->frame_id);
      union {
        float real;
        uint32_t base;
      } u_current_frames_per_second;
      u_current_frames_per_second.base = 0;
      u_current_frames_per_second.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_current_frames_per_second.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_current_frames_per_second.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_current_frames_per_second.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->current_frames_per_second = u_current_frames_per_second.real;
      offset += sizeof(this->current_frames_per_second);
      uint32_t hands_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      hands_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      hands_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      hands_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->hands_length);
      if(hands_lengthT > hands_length)
        this->hands = (strawberry_ros_msgs::LeapMotionHand*)realloc(this->hands, hands_lengthT * sizeof(strawberry_ros_msgs::LeapMotionHand));
      hands_length = hands_lengthT;
      for( uint32_t i = 0; i < hands_length; i++){
      offset += this->st_hands.deserialize(inbuffer + offset);
        memcpy( &(this->hands[i]), &(this->st_hands), sizeof(strawberry_ros_msgs::LeapMotionHand));
      }
      uint32_t gestures_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      gestures_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      gestures_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      gestures_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->gestures_length);
      if(gestures_lengthT > gestures_length)
        this->gestures = (strawberry_ros_msgs::Gesture*)realloc(this->gestures, gestures_lengthT * sizeof(strawberry_ros_msgs::Gesture));
      gestures_length = gestures_lengthT;
      for( uint32_t i = 0; i < gestures_length; i++){
      offset += this->st_gestures.deserialize(inbuffer + offset);
        memcpy( &(this->gestures[i]), &(this->st_gestures), sizeof(strawberry_ros_msgs::Gesture));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/LeapMotionHands"; };
    virtual const char * getMD5() override { return "db4fc5d19a5f6546db9cec43e7a5bbaa"; };

  };

}
#endif
