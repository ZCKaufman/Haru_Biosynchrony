#ifndef _ROS_strawberry_ros_msgs_WaitSpeakingStartsResult_h
#define _ROS_strawberry_ros_msgs_WaitSpeakingStartsResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class WaitSpeakingStartsResult : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef uint32_t _interation_duration_type;
      _interation_duration_type interation_duration;
      typedef int32_t _user_speaker_id_type;
      _user_speaker_id_type user_speaker_id;
      typedef const char* _mic_frame_type;
      _mic_frame_type mic_frame;

    WaitSpeakingStartsResult():
      success(0),
      interation_duration(0),
      user_speaker_id(0),
      mic_frame("")
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
      *(outbuffer + offset + 0) = (this->interation_duration >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->interation_duration >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->interation_duration >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->interation_duration >> (8 * 3)) & 0xFF;
      offset += sizeof(this->interation_duration);
      union {
        int32_t real;
        uint32_t base;
      } u_user_speaker_id;
      u_user_speaker_id.real = this->user_speaker_id;
      *(outbuffer + offset + 0) = (u_user_speaker_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_user_speaker_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_user_speaker_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_user_speaker_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->user_speaker_id);
      uint32_t length_mic_frame = strlen(this->mic_frame);
      varToArr(outbuffer + offset, length_mic_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->mic_frame, length_mic_frame);
      offset += length_mic_frame;
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
      this->interation_duration =  ((uint32_t) (*(inbuffer + offset)));
      this->interation_duration |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->interation_duration |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->interation_duration |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->interation_duration);
      union {
        int32_t real;
        uint32_t base;
      } u_user_speaker_id;
      u_user_speaker_id.base = 0;
      u_user_speaker_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_user_speaker_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_user_speaker_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_user_speaker_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->user_speaker_id = u_user_speaker_id.real;
      offset += sizeof(this->user_speaker_id);
      uint32_t length_mic_frame;
      arrToVar(length_mic_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mic_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mic_frame-1]=0;
      this->mic_frame = (char *)(inbuffer + offset-1);
      offset += length_mic_frame;
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/WaitSpeakingStartsResult"; };
    virtual const char * getMD5() override { return "f7e5dedec42a335f19f908a49eafedb4"; };

  };

}
#endif
