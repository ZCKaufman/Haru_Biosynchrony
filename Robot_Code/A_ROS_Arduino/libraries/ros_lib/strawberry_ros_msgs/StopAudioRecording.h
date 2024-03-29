#ifndef _ROS_SERVICE_StopAudioRecording_h
#define _ROS_SERVICE_StopAudioRecording_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char STOPAUDIORECORDING[] = "strawberry_ros_msgs/StopAudioRecording";

  class StopAudioRecordingRequest : public ros::Msg
  {
    public:
      typedef const char* _file_name_type;
      _file_name_type file_name;

    StopAudioRecordingRequest():
      file_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_file_name = strlen(this->file_name);
      varToArr(outbuffer + offset, length_file_name);
      offset += 4;
      memcpy(outbuffer + offset, this->file_name, length_file_name);
      offset += length_file_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_file_name;
      arrToVar(length_file_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file_name-1]=0;
      this->file_name = (char *)(inbuffer + offset-1);
      offset += length_file_name;
     return offset;
    }

    virtual const char * getType() override { return STOPAUDIORECORDING; };
    virtual const char * getMD5() override { return "2415261c9605b9f38867ffbbe495fc04"; };

  };

  class StopAudioRecordingResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    StopAudioRecordingResponse():
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

    virtual const char * getType() override { return STOPAUDIORECORDING; };
    virtual const char * getMD5() override { return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class StopAudioRecording {
    public:
    typedef StopAudioRecordingRequest Request;
    typedef StopAudioRecordingResponse Response;
  };

}
#endif
