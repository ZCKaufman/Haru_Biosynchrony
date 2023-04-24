#ifndef _ROS_strawberry_ros_msgs_DialogSentence_h
#define _ROS_strawberry_ros_msgs_DialogSentence_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/SentimentClassification.h"
#include "strawberry_ros_msgs/EmotionClassification.h"

namespace strawberry_ros_msgs
{

  class DialogSentence : public ros::Msg
  {
    public:
      typedef int8_t _type_type;
      _type_type type;
      typedef const char* _text_type;
      _text_type text;
      typedef const char* _genre_type;
      _genre_type genre;
      typedef const char* _emotion_type;
      _emotion_type emotion;
      typedef const char* _routine_type;
      _routine_type routine;
      typedef const char* _auto_genre_type;
      _auto_genre_type auto_genre;
      typedef const char* _auto_emotion_type;
      _auto_emotion_type auto_emotion;
      typedef const char* _auto_score_type;
      _auto_score_type auto_score;
      typedef strawberry_ros_msgs::SentimentClassification _sentiment_results_type;
      _sentiment_results_type sentiment_results;
      typedef strawberry_ros_msgs::EmotionClassification _emotion_results_type;
      _emotion_results_type emotion_results;
      enum { STATEMENT =  0      };
      enum { EXCLAMATION =  1      };
      enum { SUPPLEMENTAL =  2      };
      enum { FALLBACK =  3      };
      enum { RECOVERY =  4      };
      enum { TOPICTRANSITION =  5      };
      enum { ENTITYFOLLOWUP =  6      };
      enum { QUESTION =  7      };

    DialogSentence():
      type(0),
      text(""),
      genre(""),
      emotion(""),
      routine(""),
      auto_genre(""),
      auto_emotion(""),
      auto_score(""),
      sentiment_results(),
      emotion_results()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      uint32_t length_text = strlen(this->text);
      varToArr(outbuffer + offset, length_text);
      offset += 4;
      memcpy(outbuffer + offset, this->text, length_text);
      offset += length_text;
      uint32_t length_genre = strlen(this->genre);
      varToArr(outbuffer + offset, length_genre);
      offset += 4;
      memcpy(outbuffer + offset, this->genre, length_genre);
      offset += length_genre;
      uint32_t length_emotion = strlen(this->emotion);
      varToArr(outbuffer + offset, length_emotion);
      offset += 4;
      memcpy(outbuffer + offset, this->emotion, length_emotion);
      offset += length_emotion;
      uint32_t length_routine = strlen(this->routine);
      varToArr(outbuffer + offset, length_routine);
      offset += 4;
      memcpy(outbuffer + offset, this->routine, length_routine);
      offset += length_routine;
      uint32_t length_auto_genre = strlen(this->auto_genre);
      varToArr(outbuffer + offset, length_auto_genre);
      offset += 4;
      memcpy(outbuffer + offset, this->auto_genre, length_auto_genre);
      offset += length_auto_genre;
      uint32_t length_auto_emotion = strlen(this->auto_emotion);
      varToArr(outbuffer + offset, length_auto_emotion);
      offset += 4;
      memcpy(outbuffer + offset, this->auto_emotion, length_auto_emotion);
      offset += length_auto_emotion;
      uint32_t length_auto_score = strlen(this->auto_score);
      varToArr(outbuffer + offset, length_auto_score);
      offset += 4;
      memcpy(outbuffer + offset, this->auto_score, length_auto_score);
      offset += length_auto_score;
      offset += this->sentiment_results.serialize(outbuffer + offset);
      offset += this->emotion_results.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->type = u_type.real;
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
      uint32_t length_genre;
      arrToVar(length_genre, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_genre; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_genre-1]=0;
      this->genre = (char *)(inbuffer + offset-1);
      offset += length_genre;
      uint32_t length_emotion;
      arrToVar(length_emotion, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_emotion; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_emotion-1]=0;
      this->emotion = (char *)(inbuffer + offset-1);
      offset += length_emotion;
      uint32_t length_routine;
      arrToVar(length_routine, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_routine; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_routine-1]=0;
      this->routine = (char *)(inbuffer + offset-1);
      offset += length_routine;
      uint32_t length_auto_genre;
      arrToVar(length_auto_genre, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_auto_genre; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_auto_genre-1]=0;
      this->auto_genre = (char *)(inbuffer + offset-1);
      offset += length_auto_genre;
      uint32_t length_auto_emotion;
      arrToVar(length_auto_emotion, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_auto_emotion; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_auto_emotion-1]=0;
      this->auto_emotion = (char *)(inbuffer + offset-1);
      offset += length_auto_emotion;
      uint32_t length_auto_score;
      arrToVar(length_auto_score, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_auto_score; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_auto_score-1]=0;
      this->auto_score = (char *)(inbuffer + offset-1);
      offset += length_auto_score;
      offset += this->sentiment_results.deserialize(inbuffer + offset);
      offset += this->emotion_results.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/DialogSentence"; };
    virtual const char * getMD5() override { return "96edf27d38191a1d37b33c3a1b57b2fe"; };

  };

}
#endif
