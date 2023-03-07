#ifndef _ROS_SERVICE_GetRoutineList_h
#define _ROS_SERVICE_GetRoutineList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "idmind_tabletop_msgs/RoutineDefinition.h"

namespace idmind_tabletop_msgs
{

static const char GETROUTINELIST[] = "idmind_tabletop_msgs/GetRoutineList";

  class GetRoutineListRequest : public ros::Msg
  {
    public:

    GetRoutineListRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return GETROUTINELIST; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetRoutineListResponse : public ros::Msg
  {
    public:
      uint32_t routine_list_length;
      typedef idmind_tabletop_msgs::RoutineDefinition _routine_list_type;
      _routine_list_type st_routine_list;
      _routine_list_type * routine_list;

    GetRoutineListResponse():
      routine_list_length(0), st_routine_list(), routine_list(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->routine_list_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->routine_list_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->routine_list_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->routine_list_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->routine_list_length);
      for( uint32_t i = 0; i < routine_list_length; i++){
      offset += this->routine_list[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t routine_list_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      routine_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      routine_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      routine_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->routine_list_length);
      if(routine_list_lengthT > routine_list_length)
        this->routine_list = (idmind_tabletop_msgs::RoutineDefinition*)realloc(this->routine_list, routine_list_lengthT * sizeof(idmind_tabletop_msgs::RoutineDefinition));
      routine_list_length = routine_list_lengthT;
      for( uint32_t i = 0; i < routine_list_length; i++){
      offset += this->st_routine_list.deserialize(inbuffer + offset);
        memcpy( &(this->routine_list[i]), &(this->st_routine_list), sizeof(idmind_tabletop_msgs::RoutineDefinition));
      }
     return offset;
    }

    virtual const char * getType() override { return GETROUTINELIST; };
    virtual const char * getMD5() override { return "8ba89d75c2571bbd856ec47cdd54b71d"; };

  };

  class GetRoutineList {
    public:
    typedef GetRoutineListRequest Request;
    typedef GetRoutineListResponse Response;
  };

}
#endif
