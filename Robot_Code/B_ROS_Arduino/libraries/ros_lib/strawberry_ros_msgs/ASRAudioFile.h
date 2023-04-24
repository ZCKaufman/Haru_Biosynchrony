#ifndef _ROS_SERVICE_ASRAudioFile_h
#define _ROS_SERVICE_ASRAudioFile_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

static const char ASRAUDIOFILE[] = "strawberry_ros_msgs/ASRAudioFile";

  class ASRAudioFileRequest : public ros::Msg
  {
    public:
      typedef const char* _file_path_type;
      _file_path_type file_path;

    ASRAudioFileRequest():
      file_path("")
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
     return offset;
    }

    virtual const char * getType() override { return ASRAUDIOFILE; };
    virtual const char * getMD5() override { return "a1f82596372c52a517e1fe32d1e998e8"; };

  };

  class ASRAudioFileResponse : public ros::Msg
  {
    public:
      typedef const char* _transcript_type;
      _transcript_type transcript;

    ASRAudioFileResponse():
      transcript("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_transcript = strlen(this->transcript);
      varToArr(outbuffer + offset, length_transcript);
      offset += 4;
      memcpy(outbuffer + offset, this->transcript, length_transcript);
      offset += length_transcript;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_transcript;
      arrToVar(length_transcript, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_transcript; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_transcript-1]=0;
      this->transcript = (char *)(inbuffer + offset-1);
      offset += length_transcript;
     return offset;
    }

    virtual const char * getType() override { return ASRAUDIOFILE; };
    virtual const char * getMD5() override { return "d57af9fafe11c5c53756ce2839af175d"; };

  };

  class ASRAudioFile {
    public:
    typedef ASRAudioFileRequest Request;
    typedef ASRAudioFileResponse Response;
  };

}
#endif
