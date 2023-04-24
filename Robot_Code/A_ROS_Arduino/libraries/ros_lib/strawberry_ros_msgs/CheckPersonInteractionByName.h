#ifndef _ROS_SERVICE_CheckPersonInteractionByName_h
#define _ROS_SERVICE_CheckPersonInteractionByName_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace strawberry_ros_msgs
{

static const char CHECKPERSONINTERACTIONBYNAME[] = "strawberry_ros_msgs/CheckPersonInteractionByName";

  class CheckPersonInteractionByNameRequest : public ros::Msg
  {
    public:
      typedef const char* _person_name_type;
      _person_name_type person_name;
      typedef geometry_msgs::Point _point_type;
      _point_type point;
      typedef float _tolerance_type;
      _tolerance_type tolerance;
      typedef const char* _axis_type;
      _axis_type axis;
      enum { XYZ = "xyz" };
      enum { XY = "xy" };
      enum { XZ = "xz" };
      enum { YZ = "yz" };
      enum { X = "x" };
      enum { Y = "y" };
      enum { Z = "z" };

    CheckPersonInteractionByNameRequest():
      person_name(""),
      point(),
      tolerance(0),
      axis("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_person_name = strlen(this->person_name);
      varToArr(outbuffer + offset, length_person_name);
      offset += 4;
      memcpy(outbuffer + offset, this->person_name, length_person_name);
      offset += length_person_name;
      offset += this->point.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_tolerance;
      u_tolerance.real = this->tolerance;
      *(outbuffer + offset + 0) = (u_tolerance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_tolerance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_tolerance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_tolerance.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tolerance);
      uint32_t length_axis = strlen(this->axis);
      varToArr(outbuffer + offset, length_axis);
      offset += 4;
      memcpy(outbuffer + offset, this->axis, length_axis);
      offset += length_axis;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_person_name;
      arrToVar(length_person_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_person_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_person_name-1]=0;
      this->person_name = (char *)(inbuffer + offset-1);
      offset += length_person_name;
      offset += this->point.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_tolerance;
      u_tolerance.base = 0;
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_tolerance.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->tolerance = u_tolerance.real;
      offset += sizeof(this->tolerance);
      uint32_t length_axis;
      arrToVar(length_axis, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_axis; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_axis-1]=0;
      this->axis = (char *)(inbuffer + offset-1);
      offset += length_axis;
     return offset;
    }

    virtual const char * getType() override { return CHECKPERSONINTERACTIONBYNAME; };
    virtual const char * getMD5() override { return "c8c63dfb75670d91af9d1f42d35d2441"; };

  };

  class CheckPersonInteractionByNameResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    CheckPersonInteractionByNameResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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

    virtual const char * getType() override { return CHECKPERSONINTERACTIONBYNAME; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class CheckPersonInteractionByName {
    public:
    typedef CheckPersonInteractionByNameRequest Request;
    typedef CheckPersonInteractionByNameResponse Response;
  };

}
#endif
