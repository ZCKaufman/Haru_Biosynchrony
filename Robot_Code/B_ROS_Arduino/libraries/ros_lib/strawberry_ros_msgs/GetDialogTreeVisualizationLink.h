#ifndef _ROS_SERVICE_GetDialogTreeVisualizationLink_h
#define _ROS_SERVICE_GetDialogTreeVisualizationLink_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char GETDIALOGTREEVISUALIZATIONLINK[] = "strawberry_ros_msgs/GetDialogTreeVisualizationLink";

  class GetDialogTreeVisualizationLinkRequest : public ros::Msg
  {
    public:
      typedef uint32_t _person_id_type;
      _person_id_type person_id;

    GetDialogTreeVisualizationLinkRequest():
      person_id(0)
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
     return offset;
    }

    virtual const char * getType() override { return GETDIALOGTREEVISUALIZATIONLINK; };
    virtual const char * getMD5() override { return "9266d15c9cca61f2787d9f69171e8f98"; };

  };

  class GetDialogTreeVisualizationLinkResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;
      typedef const char* _viz_link_type;
      _viz_link_type viz_link;

    GetDialogTreeVisualizationLinkResponse():
      success(0),
      message(""),
      viz_link("")
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
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      uint32_t length_viz_link = strlen(this->viz_link);
      varToArr(outbuffer + offset, length_viz_link);
      offset += 4;
      memcpy(outbuffer + offset, this->viz_link, length_viz_link);
      offset += length_viz_link;
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
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
      uint32_t length_viz_link;
      arrToVar(length_viz_link, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_viz_link; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_viz_link-1]=0;
      this->viz_link = (char *)(inbuffer + offset-1);
      offset += length_viz_link;
     return offset;
    }

    virtual const char * getType() override { return GETDIALOGTREEVISUALIZATIONLINK; };
    virtual const char * getMD5() override { return "3d9a438c7029cbbc2d9a201893f7b3f2"; };

  };

  class GetDialogTreeVisualizationLink {
    public:
    typedef GetDialogTreeVisualizationLinkRequest Request;
    typedef GetDialogTreeVisualizationLinkResponse Response;
  };

}
#endif
