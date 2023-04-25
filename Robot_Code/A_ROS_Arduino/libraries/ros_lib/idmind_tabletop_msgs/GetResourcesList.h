#ifndef _ROS_SERVICE_GetResourcesList_h
#define _ROS_SERVICE_GetResourcesList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

static const char GETRESOURCESLIST[] = "idmind_tabletop_msgs/GetResourcesList";

  class GetResourcesListRequest : public ros::Msg
  {
    public:

    GetResourcesListRequest()
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

    virtual const char * getType() override { return GETRESOURCESLIST; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetResourcesListResponse : public ros::Msg
  {
    public:
      uint32_t list_length;
      typedef char* _list_type;
      _list_type st_list;
      _list_type * list;

    GetResourcesListResponse():
      list_length(0), st_list(), list(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->list_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->list_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->list_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->list_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->list_length);
      for( uint32_t i = 0; i < list_length; i++){
      uint32_t length_listi = strlen(this->list[i]);
      varToArr(outbuffer + offset, length_listi);
      offset += 4;
      memcpy(outbuffer + offset, this->list[i], length_listi);
      offset += length_listi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t list_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      list_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      list_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      list_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->list_length);
      if(list_lengthT > list_length)
        this->list = (char**)realloc(this->list, list_lengthT * sizeof(char*));
      list_length = list_lengthT;
      for( uint32_t i = 0; i < list_length; i++){
      uint32_t length_st_list;
      arrToVar(length_st_list, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_list; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_list-1]=0;
      this->st_list = (char *)(inbuffer + offset-1);
      offset += length_st_list;
        memcpy( &(this->list[i]), &(this->st_list), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return GETRESOURCESLIST; };
    virtual const char * getMD5() override { return "8e09fa9aad51508cfdcab3b64f048ce0"; };

  };

  class GetResourcesList {
    public:
    typedef GetResourcesListRequest Request;
    typedef GetResourcesListResponse Response;
  };

}
#endif
