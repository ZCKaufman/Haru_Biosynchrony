#ifndef _ROS_idmind_tabletop_msgs_ListeningStatus_h
#define _ROS_idmind_tabletop_msgs_ListeningStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace idmind_tabletop_msgs
{

  class ListeningStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef bool _listening_type;
      _listening_type listening;
      typedef int32_t _listening_person_type;
      _listening_person_type listening_person;
      enum { NOBODY = -2 };
      enum { EVERYBODY = -1 };

    ListeningStatus():
      header(),
      listening(0),
      listening_person(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_listening;
      u_listening.real = this->listening;
      *(outbuffer + offset + 0) = (u_listening.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->listening);
      union {
        int32_t real;
        uint32_t base;
      } u_listening_person;
      u_listening_person.real = this->listening_person;
      *(outbuffer + offset + 0) = (u_listening_person.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_listening_person.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_listening_person.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_listening_person.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->listening_person);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_listening;
      u_listening.base = 0;
      u_listening.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->listening = u_listening.real;
      offset += sizeof(this->listening);
      union {
        int32_t real;
        uint32_t base;
      } u_listening_person;
      u_listening_person.base = 0;
      u_listening_person.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_listening_person.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_listening_person.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_listening_person.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->listening_person = u_listening_person.real;
      offset += sizeof(this->listening_person);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/ListeningStatus"; };
    virtual const char * getMD5() override { return "f13b35f7c637dc965e84f202c879bb82"; };

  };

}
#endif
