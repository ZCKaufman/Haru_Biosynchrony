#ifndef _ROS_strawberry_ros_msgs_BodyPart_h
#define _ROS_strawberry_ros_msgs_BodyPart_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace strawberry_ros_msgs
{

  class BodyPart : public ros::Msg
  {
    public:
      typedef uint32_t _part_id_type;
      _part_id_type part_id;
      typedef const char* _name_type;
      _name_type name;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef float _confidence_type;
      _confidence_type confidence;
      enum { SPINE_BASE = spine_base };
      enum { SPINE_MID = spine_mid };
      enum { NECK = neck };
      enum { HEAD = head };
      enum { SHOULDER_LEFT = shoulder_left };
      enum { ELBOW_LEFT = elbow_left };
      enum { WRIST_LEFT = wrist_left };
      enum { HAND_LEFT = hand_left };
      enum { SHOULDER_RIGHT = shoulder_right };
      enum { ELBOW_RIGHT = elbow_right };
      enum { WRIST_RIGHT = wrist_right };
      enum { HAND_RIGHT = hand_right };
      enum { HIP_LEFT = hip_left };
      enum { KNEE_LEFT = knee_left };
      enum { ANKLE_LEFT = ankle_left };
      enum { FOOT_LEFT = foot_left };
      enum { HIP_RIGHT = hip_right };
      enum { KNEE_RIGHT = knee_right };
      enum { ANKLE_RIGHT = ankle_right };
      enum { FOOT_RIGHT = foot_right };
      enum { SPINE_SHOULDER = spine_shoulder };
      enum { HAND_TIP_LEFT = hand_tip_left };
      enum { THUMB_LEFT = thumb_left };
      enum { HAND_TIP_RIGHT = hand_tip_right };
      enum { THUMB_RIGHT = thumb_right };
      enum { CLAVICLE_LEFT = clavicle_left };
      enum { CLAVICLE_RIGHT = clavicle_right };
      enum { NOSE = nose };
      enum { EYE_LEFT = eye_left };
      enum { EAR_LEFT = ear_left };
      enum { EYE_RIGHT = eye_right };
      enum { EAR_RIGHT = ear_right };

    BodyPart():
      part_id(0),
      name(""),
      pose(),
      confidence(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->part_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->part_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->part_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->part_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->part_id);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      offset += this->pose.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.real = this->confidence;
      *(outbuffer + offset + 0) = (u_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->confidence);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->part_id =  ((uint32_t) (*(inbuffer + offset)));
      this->part_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->part_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->part_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->part_id);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += this->pose.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_confidence;
      u_confidence.base = 0;
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->confidence = u_confidence.real;
      offset += sizeof(this->confidence);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/BodyPart"; };
    virtual const char * getMD5() override { return "875304c61e0ca70d6f1c5260bdbb351b"; };

  };

}
#endif
