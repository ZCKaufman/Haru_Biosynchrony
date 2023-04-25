#ifndef _ROS_SERVICE_CheckPersonInteractionById_h
#define _ROS_SERVICE_CheckPersonInteractionById_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace strawberry_ros_msgs
{

static const char CHECKPERSONINTERACTIONBYID[] = "strawberry_ros_msgs/CheckPersonInteractionById";

  class CheckPersonInteractionByIdRequest : public ros::Msg
  {
    public:
      typedef uint32_t _person_id_type;
      _person_id_type person_id;
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

    CheckPersonInteractionByIdRequest():
      person_id(0),
      point(),
      tolerance(0),
      axis("")
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
      this->person_id =  ((uint32_t) (*(inbuffer + offset)));
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->person_id);
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

    virtual const char * getType() override { return CHECKPERSONINTERACTIONBYID; };
    virtual const char * getMD5() override { return "2547e5986d6b53da9a1b0febaff7334f"; };

  };

  class CheckPersonInteractionByIdResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    CheckPersonInteractionByIdResponse():
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

    virtual const char * getType() override { return CHECKPERSONINTERACTIONBYID; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class CheckPersonInteractionById {
    public:
    typedef CheckPersonInteractionByIdRequest Request;
    typedef CheckPersonInteractionByIdResponse Response;
  };

}
#endif
