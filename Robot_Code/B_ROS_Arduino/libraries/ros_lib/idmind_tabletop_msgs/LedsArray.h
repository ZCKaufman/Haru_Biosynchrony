#ifndef _ROS_idmind_tabletop_msgs_LedsArray_h
#define _ROS_idmind_tabletop_msgs_LedsArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class LedsArray : public ros::Msg
  {
    public:
      typedef bool _force_type;
      _force_type force;
      uint32_t r_length;
      typedef uint8_t _r_type;
      _r_type st_r;
      _r_type * r;
      uint32_t g_length;
      typedef uint8_t _g_type;
      _g_type st_g;
      _g_type * g;
      uint32_t b_length;
      typedef uint8_t _b_type;
      _b_type st_b;
      _b_type * b;

    LedsArray():
      force(0),
      r_length(0), st_r(), r(nullptr),
      g_length(0), st_g(), g(nullptr),
      b_length(0), st_b(), b(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_force;
      u_force.real = this->force;
      *(outbuffer + offset + 0) = (u_force.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->force);
      *(outbuffer + offset + 0) = (this->r_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->r_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->r_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->r_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->r_length);
      for( uint32_t i = 0; i < r_length; i++){
      *(outbuffer + offset + 0) = (this->r[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->r[i]);
      }
      *(outbuffer + offset + 0) = (this->g_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->g_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->g_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->g_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->g_length);
      for( uint32_t i = 0; i < g_length; i++){
      *(outbuffer + offset + 0) = (this->g[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->g[i]);
      }
      *(outbuffer + offset + 0) = (this->b_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->b_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->b_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->b_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->b_length);
      for( uint32_t i = 0; i < b_length; i++){
      *(outbuffer + offset + 0) = (this->b[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->b[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_force;
      u_force.base = 0;
      u_force.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->force = u_force.real;
      offset += sizeof(this->force);
      uint32_t r_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      r_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      r_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      r_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->r_length);
      if(r_lengthT > r_length)
        this->r = (uint8_t*)realloc(this->r, r_lengthT * sizeof(uint8_t));
      r_length = r_lengthT;
      for( uint32_t i = 0; i < r_length; i++){
      this->st_r =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_r);
        memcpy( &(this->r[i]), &(this->st_r), sizeof(uint8_t));
      }
      uint32_t g_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      g_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      g_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      g_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->g_length);
      if(g_lengthT > g_length)
        this->g = (uint8_t*)realloc(this->g, g_lengthT * sizeof(uint8_t));
      g_length = g_lengthT;
      for( uint32_t i = 0; i < g_length; i++){
      this->st_g =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_g);
        memcpy( &(this->g[i]), &(this->st_g), sizeof(uint8_t));
      }
      uint32_t b_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      b_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      b_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      b_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->b_length);
      if(b_lengthT > b_length)
        this->b = (uint8_t*)realloc(this->b, b_lengthT * sizeof(uint8_t));
      b_length = b_lengthT;
      for( uint32_t i = 0; i < b_length; i++){
      this->st_b =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_b);
        memcpy( &(this->b[i]), &(this->st_b), sizeof(uint8_t));
      }
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/LedsArray"; };
    virtual const char * getMD5() override { return "77ab43d88655f1dddee761693b672882"; };

  };

}
#endif
