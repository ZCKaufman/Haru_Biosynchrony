#ifndef _ROS_idmind_tabletop_msgs_LCDFeedback_h
#define _ROS_idmind_tabletop_msgs_LCDFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class LCDFeedback : public ros::Msg
  {
    public:
      typedef const char* _left_eye_file_type;
      _left_eye_file_type left_eye_file;
      typedef const char* _right_eye_file_type;
      _right_eye_file_type right_eye_file;
      typedef uint32_t _current_time_type;
      _current_time_type current_time;
      typedef float _progress_type;
      _progress_type progress;

    LCDFeedback():
      left_eye_file(""),
      right_eye_file(""),
      current_time(0),
      progress(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_left_eye_file = strlen(this->left_eye_file);
      varToArr(outbuffer + offset, length_left_eye_file);
      offset += 4;
      memcpy(outbuffer + offset, this->left_eye_file, length_left_eye_file);
      offset += length_left_eye_file;
      uint32_t length_right_eye_file = strlen(this->right_eye_file);
      varToArr(outbuffer + offset, length_right_eye_file);
      offset += 4;
      memcpy(outbuffer + offset, this->right_eye_file, length_right_eye_file);
      offset += length_right_eye_file;
      *(outbuffer + offset + 0) = (this->current_time >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->current_time >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->current_time >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->current_time >> (8 * 3)) & 0xFF;
      offset += sizeof(this->current_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->progress);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_left_eye_file;
      arrToVar(length_left_eye_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_left_eye_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_left_eye_file-1]=0;
      this->left_eye_file = (char *)(inbuffer + offset-1);
      offset += length_left_eye_file;
      uint32_t length_right_eye_file;
      arrToVar(length_right_eye_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_right_eye_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_right_eye_file-1]=0;
      this->right_eye_file = (char *)(inbuffer + offset-1);
      offset += length_right_eye_file;
      this->current_time =  ((uint32_t) (*(inbuffer + offset)));
      this->current_time |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->current_time |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->current_time |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->current_time);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->progress));
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/LCDFeedback"; };
    virtual const char * getMD5() override { return "f704ea9957cb4574f6f8c4f55ff0f50d"; };

  };

}
#endif
