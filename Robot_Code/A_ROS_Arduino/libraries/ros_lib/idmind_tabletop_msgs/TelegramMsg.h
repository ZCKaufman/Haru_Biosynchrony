#ifndef _ROS_idmind_tabletop_msgs_TelegramMsg_h
#define _ROS_idmind_tabletop_msgs_TelegramMsg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class TelegramMsg : public ros::Msg
  {
    public:
      typedef uint64_t _msg_id_type;
      _msg_id_type msg_id;
      typedef uint64_t _msg_timestamp_sec_type;
      _msg_timestamp_sec_type msg_timestamp_sec;
      typedef uint64_t _msg_timestamp_nsec_type;
      _msg_timestamp_nsec_type msg_timestamp_nsec;
      typedef uint64_t _chat_id_type;
      _chat_id_type chat_id;
      typedef const char* _user_name_type;
      _user_name_type user_name;
      typedef const char* _user_firstname_type;
      _user_firstname_type user_firstname;
      typedef uint8_t _type_type;
      _type_type type;
      typedef const char* _text_type;
      _text_type text;
      typedef const char* _emoji_type;
      _emoji_type emoji;
      typedef uint64_t _emoji_routine_id_type;
      _emoji_routine_id_type emoji_routine_id;
      typedef const char* _harumoji_type;
      _harumoji_type harumoji;
      typedef uint64_t _harumoji_routine_id_type;
      _harumoji_routine_id_type harumoji_routine_id;
      typedef const char* _audio_file_path_type;
      _audio_file_path_type audio_file_path;
      typedef bool _is_audio_transcribed_type;
      _is_audio_transcribed_type is_audio_transcribed;
      typedef const char* _audio_transcription_type;
      _audio_transcription_type audio_transcription;
      typedef const char* _photo_file_path_type;
      _photo_file_path_type photo_file_path;
      enum { TEXT =  0              };
      enum { AUDIO =  1              };
      enum { PHOTO =  2              };
      enum { EMOJI =  3              };
      enum { HARUMOJI =  4           };
      enum { REQUESTED_PHOTO =  5    };

    TelegramMsg():
      msg_id(0),
      msg_timestamp_sec(0),
      msg_timestamp_nsec(0),
      chat_id(0),
      user_name(""),
      user_firstname(""),
      type(0),
      text(""),
      emoji(""),
      emoji_routine_id(0),
      harumoji(""),
      harumoji_routine_id(0),
      audio_file_path(""),
      is_audio_transcribed(0),
      audio_transcription(""),
      photo_file_path("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->msg_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->msg_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->msg_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->msg_id >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->msg_id >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->msg_id >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->msg_id >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->msg_id >> (8 * 7)) & 0xFF;
      offset += sizeof(this->msg_id);
      *(outbuffer + offset + 0) = (this->msg_timestamp_sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->msg_timestamp_sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->msg_timestamp_sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->msg_timestamp_sec >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->msg_timestamp_sec >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->msg_timestamp_sec >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->msg_timestamp_sec >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->msg_timestamp_sec >> (8 * 7)) & 0xFF;
      offset += sizeof(this->msg_timestamp_sec);
      *(outbuffer + offset + 0) = (this->msg_timestamp_nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->msg_timestamp_nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->msg_timestamp_nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->msg_timestamp_nsec >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->msg_timestamp_nsec >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->msg_timestamp_nsec >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->msg_timestamp_nsec >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->msg_timestamp_nsec >> (8 * 7)) & 0xFF;
      offset += sizeof(this->msg_timestamp_nsec);
      *(outbuffer + offset + 0) = (this->chat_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->chat_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->chat_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->chat_id >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->chat_id >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->chat_id >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->chat_id >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->chat_id >> (8 * 7)) & 0xFF;
      offset += sizeof(this->chat_id);
      uint32_t length_user_name = strlen(this->user_name);
      varToArr(outbuffer + offset, length_user_name);
      offset += 4;
      memcpy(outbuffer + offset, this->user_name, length_user_name);
      offset += length_user_name;
      uint32_t length_user_firstname = strlen(this->user_firstname);
      varToArr(outbuffer + offset, length_user_firstname);
      offset += 4;
      memcpy(outbuffer + offset, this->user_firstname, length_user_firstname);
      offset += length_user_firstname;
      *(outbuffer + offset + 0) = (this->type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      uint32_t length_text = strlen(this->text);
      varToArr(outbuffer + offset, length_text);
      offset += 4;
      memcpy(outbuffer + offset, this->text, length_text);
      offset += length_text;
      uint32_t length_emoji = strlen(this->emoji);
      varToArr(outbuffer + offset, length_emoji);
      offset += 4;
      memcpy(outbuffer + offset, this->emoji, length_emoji);
      offset += length_emoji;
      *(outbuffer + offset + 0) = (this->emoji_routine_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->emoji_routine_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->emoji_routine_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->emoji_routine_id >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->emoji_routine_id >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->emoji_routine_id >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->emoji_routine_id >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->emoji_routine_id >> (8 * 7)) & 0xFF;
      offset += sizeof(this->emoji_routine_id);
      uint32_t length_harumoji = strlen(this->harumoji);
      varToArr(outbuffer + offset, length_harumoji);
      offset += 4;
      memcpy(outbuffer + offset, this->harumoji, length_harumoji);
      offset += length_harumoji;
      *(outbuffer + offset + 0) = (this->harumoji_routine_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->harumoji_routine_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->harumoji_routine_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->harumoji_routine_id >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->harumoji_routine_id >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->harumoji_routine_id >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->harumoji_routine_id >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->harumoji_routine_id >> (8 * 7)) & 0xFF;
      offset += sizeof(this->harumoji_routine_id);
      uint32_t length_audio_file_path = strlen(this->audio_file_path);
      varToArr(outbuffer + offset, length_audio_file_path);
      offset += 4;
      memcpy(outbuffer + offset, this->audio_file_path, length_audio_file_path);
      offset += length_audio_file_path;
      union {
        bool real;
        uint8_t base;
      } u_is_audio_transcribed;
      u_is_audio_transcribed.real = this->is_audio_transcribed;
      *(outbuffer + offset + 0) = (u_is_audio_transcribed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_audio_transcribed);
      uint32_t length_audio_transcription = strlen(this->audio_transcription);
      varToArr(outbuffer + offset, length_audio_transcription);
      offset += 4;
      memcpy(outbuffer + offset, this->audio_transcription, length_audio_transcription);
      offset += length_audio_transcription;
      uint32_t length_photo_file_path = strlen(this->photo_file_path);
      varToArr(outbuffer + offset, length_photo_file_path);
      offset += 4;
      memcpy(outbuffer + offset, this->photo_file_path, length_photo_file_path);
      offset += length_photo_file_path;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->msg_id =  ((uint64_t) (*(inbuffer + offset)));
      this->msg_id |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->msg_id |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->msg_id |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->msg_id |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->msg_id |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->msg_id |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->msg_id |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->msg_id);
      this->msg_timestamp_sec =  ((uint64_t) (*(inbuffer + offset)));
      this->msg_timestamp_sec |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->msg_timestamp_sec |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->msg_timestamp_sec |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->msg_timestamp_sec |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->msg_timestamp_sec |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->msg_timestamp_sec |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->msg_timestamp_sec |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->msg_timestamp_sec);
      this->msg_timestamp_nsec =  ((uint64_t) (*(inbuffer + offset)));
      this->msg_timestamp_nsec |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->msg_timestamp_nsec |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->msg_timestamp_nsec |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->msg_timestamp_nsec |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->msg_timestamp_nsec |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->msg_timestamp_nsec |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->msg_timestamp_nsec |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->msg_timestamp_nsec);
      this->chat_id =  ((uint64_t) (*(inbuffer + offset)));
      this->chat_id |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->chat_id |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->chat_id |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->chat_id |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->chat_id |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->chat_id |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->chat_id |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->chat_id);
      uint32_t length_user_name;
      arrToVar(length_user_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_user_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_user_name-1]=0;
      this->user_name = (char *)(inbuffer + offset-1);
      offset += length_user_name;
      uint32_t length_user_firstname;
      arrToVar(length_user_firstname, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_user_firstname; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_user_firstname-1]=0;
      this->user_firstname = (char *)(inbuffer + offset-1);
      offset += length_user_firstname;
      this->type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->type);
      uint32_t length_text;
      arrToVar(length_text, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_text-1]=0;
      this->text = (char *)(inbuffer + offset-1);
      offset += length_text;
      uint32_t length_emoji;
      arrToVar(length_emoji, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_emoji; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_emoji-1]=0;
      this->emoji = (char *)(inbuffer + offset-1);
      offset += length_emoji;
      this->emoji_routine_id =  ((uint64_t) (*(inbuffer + offset)));
      this->emoji_routine_id |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->emoji_routine_id |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->emoji_routine_id |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->emoji_routine_id |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->emoji_routine_id |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->emoji_routine_id |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->emoji_routine_id |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->emoji_routine_id);
      uint32_t length_harumoji;
      arrToVar(length_harumoji, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_harumoji; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_harumoji-1]=0;
      this->harumoji = (char *)(inbuffer + offset-1);
      offset += length_harumoji;
      this->harumoji_routine_id =  ((uint64_t) (*(inbuffer + offset)));
      this->harumoji_routine_id |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->harumoji_routine_id |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->harumoji_routine_id |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->harumoji_routine_id |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->harumoji_routine_id |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->harumoji_routine_id |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->harumoji_routine_id |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->harumoji_routine_id);
      uint32_t length_audio_file_path;
      arrToVar(length_audio_file_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_audio_file_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_audio_file_path-1]=0;
      this->audio_file_path = (char *)(inbuffer + offset-1);
      offset += length_audio_file_path;
      union {
        bool real;
        uint8_t base;
      } u_is_audio_transcribed;
      u_is_audio_transcribed.base = 0;
      u_is_audio_transcribed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_audio_transcribed = u_is_audio_transcribed.real;
      offset += sizeof(this->is_audio_transcribed);
      uint32_t length_audio_transcription;
      arrToVar(length_audio_transcription, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_audio_transcription; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_audio_transcription-1]=0;
      this->audio_transcription = (char *)(inbuffer + offset-1);
      offset += length_audio_transcription;
      uint32_t length_photo_file_path;
      arrToVar(length_photo_file_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_photo_file_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_photo_file_path-1]=0;
      this->photo_file_path = (char *)(inbuffer + offset-1);
      offset += length_photo_file_path;
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/TelegramMsg"; };
    virtual const char * getMD5() override { return "4a9b10bf7346d413ec5d112bd947fc1a"; };

  };

}
#endif
