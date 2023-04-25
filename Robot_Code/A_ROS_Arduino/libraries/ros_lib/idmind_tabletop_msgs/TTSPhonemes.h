#ifndef _ROS_idmind_tabletop_msgs_TTSPhonemes_h
#define _ROS_idmind_tabletop_msgs_TTSPhonemes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace idmind_tabletop_msgs
{

  class TTSPhonemes : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _file_type;
      _file_type file;
      uint32_t starttime_length;
      typedef float _starttime_type;
      _starttime_type st_starttime;
      _starttime_type * starttime;
      uint32_t stoptime_length;
      typedef float _stoptime_type;
      _stoptime_type st_stoptime;
      _stoptime_type * stoptime;
      uint32_t stress_length;
      typedef bool _stress_type;
      _stress_type st_stress;
      _stress_type * stress;
      uint32_t phoneme_length;
      typedef char* _phoneme_type;
      _phoneme_type st_phoneme;
      _phoneme_type * phoneme;

    TTSPhonemes():
      header(),
      file(""),
      starttime_length(0), st_starttime(), starttime(nullptr),
      stoptime_length(0), st_stoptime(), stoptime(nullptr),
      stress_length(0), st_stress(), stress(nullptr),
      phoneme_length(0), st_phoneme(), phoneme(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_file = strlen(this->file);
      varToArr(outbuffer + offset, length_file);
      offset += 4;
      memcpy(outbuffer + offset, this->file, length_file);
      offset += length_file;
      *(outbuffer + offset + 0) = (this->starttime_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->starttime_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->starttime_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->starttime_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->starttime_length);
      for( uint32_t i = 0; i < starttime_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->starttime[i]);
      }
      *(outbuffer + offset + 0) = (this->stoptime_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stoptime_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stoptime_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stoptime_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stoptime_length);
      for( uint32_t i = 0; i < stoptime_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->stoptime[i]);
      }
      *(outbuffer + offset + 0) = (this->stress_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stress_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stress_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stress_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stress_length);
      for( uint32_t i = 0; i < stress_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_stressi;
      u_stressi.real = this->stress[i];
      *(outbuffer + offset + 0) = (u_stressi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stress[i]);
      }
      *(outbuffer + offset + 0) = (this->phoneme_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->phoneme_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->phoneme_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->phoneme_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->phoneme_length);
      for( uint32_t i = 0; i < phoneme_length; i++){
      uint32_t length_phonemei = strlen(this->phoneme[i]);
      varToArr(outbuffer + offset, length_phonemei);
      offset += 4;
      memcpy(outbuffer + offset, this->phoneme[i], length_phonemei);
      offset += length_phonemei;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_file;
      arrToVar(length_file, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_file; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_file-1]=0;
      this->file = (char *)(inbuffer + offset-1);
      offset += length_file;
      uint32_t starttime_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      starttime_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      starttime_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      starttime_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->starttime_length);
      if(starttime_lengthT > starttime_length)
        this->starttime = (float*)realloc(this->starttime, starttime_lengthT * sizeof(float));
      starttime_length = starttime_lengthT;
      for( uint32_t i = 0; i < starttime_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_starttime));
        memcpy( &(this->starttime[i]), &(this->st_starttime), sizeof(float));
      }
      uint32_t stoptime_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stoptime_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stoptime_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stoptime_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stoptime_length);
      if(stoptime_lengthT > stoptime_length)
        this->stoptime = (float*)realloc(this->stoptime, stoptime_lengthT * sizeof(float));
      stoptime_length = stoptime_lengthT;
      for( uint32_t i = 0; i < stoptime_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_stoptime));
        memcpy( &(this->stoptime[i]), &(this->st_stoptime), sizeof(float));
      }
      uint32_t stress_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      stress_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      stress_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      stress_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->stress_length);
      if(stress_lengthT > stress_length)
        this->stress = (bool*)realloc(this->stress, stress_lengthT * sizeof(bool));
      stress_length = stress_lengthT;
      for( uint32_t i = 0; i < stress_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_stress;
      u_st_stress.base = 0;
      u_st_stress.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_stress = u_st_stress.real;
      offset += sizeof(this->st_stress);
        memcpy( &(this->stress[i]), &(this->st_stress), sizeof(bool));
      }
      uint32_t phoneme_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      phoneme_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      phoneme_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      phoneme_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->phoneme_length);
      if(phoneme_lengthT > phoneme_length)
        this->phoneme = (char**)realloc(this->phoneme, phoneme_lengthT * sizeof(char*));
      phoneme_length = phoneme_lengthT;
      for( uint32_t i = 0; i < phoneme_length; i++){
      uint32_t length_st_phoneme;
      arrToVar(length_st_phoneme, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_phoneme; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_phoneme-1]=0;
      this->st_phoneme = (char *)(inbuffer + offset-1);
      offset += length_st_phoneme;
        memcpy( &(this->phoneme[i]), &(this->st_phoneme), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/TTSPhonemes"; };
    virtual const char * getMD5() override { return "3be2b4284c69400ea2d6e25a04852585"; };

  };

}
#endif
