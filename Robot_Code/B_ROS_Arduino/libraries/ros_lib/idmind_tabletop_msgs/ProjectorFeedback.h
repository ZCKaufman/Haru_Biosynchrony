#ifndef _ROS_idmind_tabletop_msgs_ProjectorFeedback_h
#define _ROS_idmind_tabletop_msgs_ProjectorFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class ProjectorFeedback : public ros::Msg
  {
    public:
      typedef const char* _file_type;
      _file_type file;
      typedef float _progress_type;
      _progress_type progress;
      typedef uint32_t _current_time_type;
      _current_time_type current_time;
      typedef uint32_t _current_frame_type;
      _current_frame_type current_frame;

    ProjectorFeedback():
      file(""),
      progress(0),
      current_time(0),
      current_frame(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_file = strlen(this->file);
      varToArr(outbuffer + offset, length_file);
      offset += 4;
      memcpy(outbuffer + offset, this->file, length_file);
      offset += length_file;
      offset += serializeAvrFloat64(outbuffer + offset, this->progress);
      *(outbuffer + offset + 0) = (this->current_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->current_time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->current_time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_time);
      *(outbuffer + offset + 0) = (this->current_frame >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_frame >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->current_frame >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->current_frame >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_frame);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_file;
      arrToVar(length_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file-1]=0;
      this->file = (char *)(inbuffer + offset-1);
      offset += length_file;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->progress));
      this->current_time =  ((uint32_t) (*(inbuffer + offset)));
      this->current_time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->current_time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->current_time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->current_time);
      this->current_frame =  ((uint32_t) (*(inbuffer + offset)));
      this->current_frame |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->current_frame |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->current_frame |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->current_frame);
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/ProjectorFeedback"; };
    virtual const char * getMD5() override { return "bfdf44b234c0bb7f699aa78cafca23c1"; };

  };

}
#endif
