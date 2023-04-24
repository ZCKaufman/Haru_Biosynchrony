#ifndef _ROS_SERVICE_StartAudioRecording_h
#define _ROS_SERVICE_StartAudioRecording_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char STARTAUDIORECORDING[] = "strawberry_ros_msgs/StartAudioRecording";

  class StartAudioRecordingRequest : public ros::Msg
  {
    public:
      typedef const char* _file_path_type;
      _file_path_type file_path;
      typedef const char* _file_prefix_type;
      _file_prefix_type file_prefix;

    StartAudioRecordingRequest():
      file_path(""),
      file_prefix("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_file_path = strlen(this->file_path);
      varToArr(outbuffer + offset, length_file_path);
      offset += 4;
      memcpy(outbuffer + offset, this->file_path, length_file_path);
      offset += length_file_path;
      uint32_t length_file_prefix = strlen(this->file_prefix);
      varToArr(outbuffer + offset, length_file_prefix);
      offset += 4;
      memcpy(outbuffer + offset, this->file_prefix, length_file_prefix);
      offset += length_file_prefix;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_file_path;
      arrToVar(length_file_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file_path-1]=0;
      this->file_path = (char *)(inbuffer + offset-1);
      offset += length_file_path;
      uint32_t length_file_prefix;
      arrToVar(length_file_prefix, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file_prefix; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file_prefix-1]=0;
      this->file_prefix = (char *)(inbuffer + offset-1);
      offset += length_file_prefix;
     return offset;
    }

    virtual const char * getType() override { return STARTAUDIORECORDING; };
    virtual const char * getMD5() override { return "3621d1e08466f7bcdedaacc8a0ad215f"; };

  };

  class StartAudioRecordingResponse : public ros::Msg
  {
    public:
      typedef const char* _file_name_type;
      _file_name_type file_name;
      typedef bool _success_type;
      _success_type success;

    StartAudioRecordingResponse():
      file_name(""),
      success(0)
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
      uint32_t length_file_name;
      arrToVar(length_file_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file_name-1]=0;
      this->file_name = (char *)(inbuffer + offset-1);
      offset += length_file_name;
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

    virtual const char * getType() override { return STARTAUDIORECORDING; };
    virtual const char * getMD5() override { return "6e1727f3fbee4b1df6a5726de8cd03a1"; };

  };

  class StartAudioRecording {
    public:
    typedef StartAudioRecordingRequest Request;
    typedef StartAudioRecordingResponse Response;
  };

}
#endif
