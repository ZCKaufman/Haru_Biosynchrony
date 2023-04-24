#ifndef _ROS_strawberry_ros_msgs_WaitSpeakingStopsFeedback_h
#define _ROS_strawberry_ros_msgs_WaitSpeakingStopsFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace strawberry_ros_msgs
{

  class WaitSpeakingStopsFeedback : public ros::Msg
  {
    public:
      uint32_t person_speaking_id_length;
      typedef int32_t _person_speaking_id_type;
      _person_speaking_id_type st_person_speaking_id;
      _person_speaking_id_type * person_speaking_id;
      uint32_t mic_frame_length;
      typedef char* _mic_frame_type;
      _mic_frame_type st_mic_frame;
      _mic_frame_type * mic_frame;

    WaitSpeakingStopsFeedback():
      person_speaking_id_length(0), st_person_speaking_id(), person_speaking_id(nullptr),
      mic_frame_length(0), st_mic_frame(), mic_frame(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->person_speaking_id_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->person_speaking_id_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->person_speaking_id_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->person_speaking_id_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->person_speaking_id_length);
      for( uint32_t i = 0; i < person_speaking_id_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_person_speaking_idi;
      u_person_speaking_idi.real = this->person_speaking_id[i];
      *(outbuffer + offset + 0) = (u_person_speaking_idi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_person_speaking_idi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_person_speaking_idi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_person_speaking_idi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->person_speaking_id[i]);
      }
      *(outbuffer + offset + 0) = (this->mic_frame_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->mic_frame_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->mic_frame_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->mic_frame_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->mic_frame_length);
      for( uint32_t i = 0; i < mic_frame_length; i++){
      uint32_t length_mic_framei = strlen(this->mic_frame[i]);
      varToArr(outbuffer + offset, length_mic_framei);
      offset += 4;
      memcpy(outbuffer + offset, this->mic_frame[i], length_mic_framei);
      offset += length_mic_framei;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t person_speaking_id_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      person_speaking_id_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      person_speaking_id_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      person_speaking_id_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->person_speaking_id_length);
      if(person_speaking_id_lengthT > person_speaking_id_length)
        this->person_speaking_id = (int32_t*)realloc(this->person_speaking_id, person_speaking_id_lengthT * sizeof(int32_t));
      person_speaking_id_length = person_speaking_id_lengthT;
      for( uint32_t i = 0; i < person_speaking_id_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_person_speaking_id;
      u_st_person_speaking_id.base = 0;
      u_st_person_speaking_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_person_speaking_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_person_speaking_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_person_speaking_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_person_speaking_id = u_st_person_speaking_id.real;
      offset += sizeof(this->st_person_speaking_id);
        memcpy( &(this->person_speaking_id[i]), &(this->st_person_speaking_id), sizeof(int32_t));
      }
      uint32_t mic_frame_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      mic_frame_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      mic_frame_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      mic_frame_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->mic_frame_length);
      if(mic_frame_lengthT > mic_frame_length)
        this->mic_frame = (char**)realloc(this->mic_frame, mic_frame_lengthT * sizeof(char*));
      mic_frame_length = mic_frame_lengthT;
      for( uint32_t i = 0; i < mic_frame_length; i++){
      uint32_t length_st_mic_frame;
      arrToVar(length_st_mic_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_mic_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_mic_frame-1]=0;
      this->st_mic_frame = (char *)(inbuffer + offset-1);
      offset += length_st_mic_frame;
        memcpy( &(this->mic_frame[i]), &(this->st_mic_frame), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/WaitSpeakingStopsFeedback"; };
    virtual const char * getMD5() override { return "33bbde893ead739b6b2a1cde52256889"; };

  };

}
#endif
