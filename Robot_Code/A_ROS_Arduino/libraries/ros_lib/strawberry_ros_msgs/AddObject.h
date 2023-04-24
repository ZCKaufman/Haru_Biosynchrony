#ifndef _ROS_SERVICE_AddObject_h
#define _ROS_SERVICE_AddObject_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/Object.h"

namespace strawberry_ros_msgs
{

static const char ADDOBJECT[] = "strawberry_ros_msgs/AddObject";

  class AddObjectRequest : public ros::Msg
  {
    public:
      typedef strawberry_ros_msgs::Object _new_object_type;
      _new_object_type new_object;

    AddObjectRequest():
      new_object()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->new_object.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->new_object.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return ADDOBJECT; };
    virtual const char * getMD5() override { return "7f90c9d34546083db3fd0c51ee194a83"; };

  };

  class AddObjectResponse : public ros::Msg
  {
    public:
      typedef const char* _message_type;
      _message_type message;

    AddObjectResponse():
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    virtual const char * getType() override { return ADDOBJECT; };
    virtual const char * getMD5() override { return "5f003d6bcc824cbd51361d66d8e4f76c"; };

  };

  class AddObject {
    public:
    typedef AddObjectRequest Request;
    typedef AddObjectResponse Response;
  };

}
#endif
