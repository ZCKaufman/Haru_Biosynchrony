#ifndef _ROS_strawberry_ros_msgs_Gesture_h
#define _ROS_strawberry_ros_msgs_Gesture_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class Gesture : public ros::Msg
  {
    public:
      typedef uint32_t _person_id_type;
      _person_id_type person_id;
      typedef uint8_t _type_type;
      _type_type type;
      typedef const char* _name_type;
      _name_type name;
      typedef uint32_t _gesture_id_type;
      _gesture_id_type gesture_id;
      typedef float _confidence_type;
      _confidence_type confidence;
      typedef float _progress_type;
      _progress_type progress;
      enum { DISCRETE =  0 };
      enum { CONTINUOUS =  1 };

    Gesture():
      person_id(0),
      type(0),
      name(""),
      gesture_id(0),
      confidence(0),
      progress(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->person_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->person_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->person_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->person_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->person_id);
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->gesture_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->gesture_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->gesture_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->gesture_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->gesture_id);
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
      union {
        float real;
        uint32_t base;
      } u_progress;
      u_progress.real = this->progress;
      *(outbuffer + offset + 0) = (u_progress.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_progress.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_progress.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_progress.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->progress);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->person_id =  ((uint32_t) (*(inbuffer + offset)));
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->person_id);
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      this->gesture_id =  ((uint32_t) (*(inbuffer + offset)));
      this->gesture_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->gesture_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->gesture_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->gesture_id);
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
      union {
        float real;
        uint32_t base;
      } u_progress;
      u_progress.base = 0;
      u_progress.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_progress.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_progress.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_progress.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->progress = u_progress.real;
      offset += sizeof(this->progress);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/Gesture"; };
    virtual const char * getMD5() override { return "5dc679f3f402a6db21d0b05f10c50346"; };

  };

}
#endif
