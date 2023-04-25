#ifndef _ROS_haru_encouraging_mediator_msgs_UnityCameraMotion_h
#define _ROS_haru_encouraging_mediator_msgs_UnityCameraMotion_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"

namespace haru_encouraging_mediator_msgs
{

  class UnityCameraMotion : public ros::Msg
  {
    public:
      typedef bool _move_type;
      _move_type move;
      typedef bool _turn_type;
      _turn_type turn;
      typedef geometry_msgs::Vector3 _direction_type;
      _direction_type direction;
      typedef float _speed_type;
      _speed_type speed;

    UnityCameraMotion():
      move(0),
      turn(0),
      direction(),
      speed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_move;
      u_move.real = this->move;
      *(outbuffer + offset + 0) = (u_move.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->move);
      union {
        bool real;
        uint8_t base;
      } u_turn;
      u_turn.real = this->turn;
      *(outbuffer + offset + 0) = (u_turn.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->turn);
      offset += this->direction.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_move;
      u_move.base = 0;
      u_move.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->move = u_move.real;
      offset += sizeof(this->move);
      union {
        bool real;
        uint8_t base;
      } u_turn;
      u_turn.base = 0;
      u_turn.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->turn = u_turn.real;
      offset += sizeof(this->turn);
      offset += this->direction.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
     return offset;
    }

    virtual const char * getType() override { return "haru_encouraging_mediator_msgs/UnityCameraMotion"; };
    virtual const char * getMD5() override { return "0e7ae56ac1cebc7c3ec38319b57497b9"; };

  };

}
#endif
