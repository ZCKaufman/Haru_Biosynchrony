#ifndef _ROS_strawberry_ros_msgs_DialogResult_h
#define _ROS_strawberry_ros_msgs_DialogResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "strawberry_ros_msgs/DialogSentence.h"
#include "strawberry_ros_msgs/DialogSlu.h"
#include "strawberry_ros_msgs/DialogSentimentResult.h"
#include "strawberry_ros_msgs/EmotionClassification.h"
#include "strawberry_ros_msgs/DialogSlot.h"

namespace strawberry_ros_msgs
{

  class DialogResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef uint32_t _person_id_type;
      _person_id_type person_id;
      typedef const char* _utterance_type;
      _utterance_type utterance;
      uint32_t utterance_sentences_length;
      typedef strawberry_ros_msgs::DialogSentence _utterance_sentences_type;
      _utterance_sentences_type st_utterance_sentences;
      _utterance_sentences_type * utterance_sentences;
      typedef const char* _language_code_type;
      _language_code_type language_code;
      typedef const char* _fulfillment_text_type;
      _fulfillment_text_type fulfillment_text;
      uint32_t fulfillment_messages_length;
      typedef char* _fulfillment_messages_type;
      _fulfillment_messages_type st_fulfillment_messages;
      _fulfillment_messages_type * fulfillment_messages;
      uint32_t fulfillment_sentences_length;
      typedef strawberry_ros_msgs::DialogSentence _fulfillment_sentences_type;
      _fulfillment_sentences_type st_fulfillment_sentences;
      _fulfillment_sentences_type * fulfillment_sentences;
      typedef const char* _dialogue_act_type;
      _dialogue_act_type dialogue_act;
      typedef const char* _topic_type;
      _topic_type topic;
      typedef const char* _subtopic_type;
      _subtopic_type subtopic;
      typedef const char* _question_type;
      _question_type question;
      typedef bool _conversation_finished_type;
      _conversation_finished_type conversation_finished;
      typedef uint32_t _suggested_routine_id_type;
      _suggested_routine_id_type suggested_routine_id;
      typedef strawberry_ros_msgs::DialogSlu _slu_result_type;
      _slu_result_type slu_result;
      typedef strawberry_ros_msgs::DialogSentimentResult _sentiment_results_type;
      _sentiment_results_type sentiment_results;
      typedef strawberry_ros_msgs::EmotionClassification _utterance_emotion_type;
      _utterance_emotion_type utterance_emotion;
      typedef strawberry_ros_msgs::EmotionClassification _fulfillment_emotion_type;
      _fulfillment_emotion_type fulfillment_emotion;
      uint32_t slots_length;
      typedef strawberry_ros_msgs::DialogSlot _slots_type;
      _slots_type st_slots;
      _slots_type * slots;

    DialogResult():
      header(),
      person_id(0),
      utterance(""),
      utterance_sentences_length(0), st_utterance_sentences(), utterance_sentences(nullptr),
      language_code(""),
      fulfillment_text(""),
      fulfillment_messages_length(0), st_fulfillment_messages(), fulfillment_messages(nullptr),
      fulfillment_sentences_length(0), st_fulfillment_sentences(), fulfillment_sentences(nullptr),
      dialogue_act(""),
      topic(""),
      subtopic(""),
      question(""),
      conversation_finished(0),
      suggested_routine_id(0),
      slu_result(),
      sentiment_results(),
      utterance_emotion(),
      fulfillment_emotion(),
      slots_length(0), st_slots(), slots(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->person_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->person_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->person_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->person_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->person_id);
      uint32_t length_utterance = strlen(this->utterance);
      varToArr(outbuffer + offset, length_utterance);
      offset += 4;
      memcpy(outbuffer + offset, this->utterance, length_utterance);
      offset += length_utterance;
      *(outbuffer + offset + 0) = (this->utterance_sentences_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->utterance_sentences_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->utterance_sentences_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->utterance_sentences_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->utterance_sentences_length);
      for( uint32_t i = 0; i < utterance_sentences_length; i++){
      offset += this->utterance_sentences[i].serialize(outbuffer + offset);
      }
      uint32_t length_language_code = strlen(this->language_code);
      varToArr(outbuffer + offset, length_language_code);
      offset += 4;
      memcpy(outbuffer + offset, this->language_code, length_language_code);
      offset += length_language_code;
      uint32_t length_fulfillment_text = strlen(this->fulfillment_text);
      varToArr(outbuffer + offset, length_fulfillment_text);
      offset += 4;
      memcpy(outbuffer + offset, this->fulfillment_text, length_fulfillment_text);
      offset += length_fulfillment_text;
      *(outbuffer + offset + 0) = (this->fulfillment_messages_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fulfillment_messages_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fulfillment_messages_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fulfillment_messages_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fulfillment_messages_length);
      for( uint32_t i = 0; i < fulfillment_messages_length; i++){
      uint32_t length_fulfillment_messagesi = strlen(this->fulfillment_messages[i]);
      varToArr(outbuffer + offset, length_fulfillment_messagesi);
      offset += 4;
      memcpy(outbuffer + offset, this->fulfillment_messages[i], length_fulfillment_messagesi);
      offset += length_fulfillment_messagesi;
      }
      *(outbuffer + offset + 0) = (this->fulfillment_sentences_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fulfillment_sentences_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fulfillment_sentences_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fulfillment_sentences_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fulfillment_sentences_length);
      for( uint32_t i = 0; i < fulfillment_sentences_length; i++){
      offset += this->fulfillment_sentences[i].serialize(outbuffer + offset);
      }
      uint32_t length_dialogue_act = strlen(this->dialogue_act);
      varToArr(outbuffer + offset, length_dialogue_act);
      offset += 4;
      memcpy(outbuffer + offset, this->dialogue_act, length_dialogue_act);
      offset += length_dialogue_act;
      uint32_t length_topic = strlen(this->topic);
      varToArr(outbuffer + offset, length_topic);
      offset += 4;
      memcpy(outbuffer + offset, this->topic, length_topic);
      offset += length_topic;
      uint32_t length_subtopic = strlen(this->subtopic);
      varToArr(outbuffer + offset, length_subtopic);
      offset += 4;
      memcpy(outbuffer + offset, this->subtopic, length_subtopic);
      offset += length_subtopic;
      uint32_t length_question = strlen(this->question);
      varToArr(outbuffer + offset, length_question);
      offset += 4;
      memcpy(outbuffer + offset, this->question, length_question);
      offset += length_question;
      union {
        bool real;
        uint8_t base;
      } u_conversation_finished;
      u_conversation_finished.real = this->conversation_finished;
      *(outbuffer + offset + 0) = (u_conversation_finished.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->conversation_finished);
      *(outbuffer + offset + 0) = (this->suggested_routine_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->suggested_routine_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->suggested_routine_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->suggested_routine_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->suggested_routine_id);
      offset += this->slu_result.serialize(outbuffer + offset);
      offset += this->sentiment_results.serialize(outbuffer + offset);
      offset += this->utterance_emotion.serialize(outbuffer + offset);
      offset += this->fulfillment_emotion.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->slots_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->slots_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->slots_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->slots_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->slots_length);
      for( uint32_t i = 0; i < slots_length; i++){
      offset += this->slots[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->person_id =  ((uint32_t) (*(inbuffer + offset)));
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->person_id);
      uint32_t length_utterance;
      arrToVar(length_utterance, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_utterance; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_utterance-1]=0;
      this->utterance = (char *)(inbuffer + offset-1);
      offset += length_utterance;
      uint32_t utterance_sentences_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      utterance_sentences_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      utterance_sentences_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      utterance_sentences_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->utterance_sentences_length);
      if(utterance_sentences_lengthT > utterance_sentences_length)
        this->utterance_sentences = (strawberry_ros_msgs::DialogSentence*)realloc(this->utterance_sentences, utterance_sentences_lengthT * sizeof(strawberry_ros_msgs::DialogSentence));
      utterance_sentences_length = utterance_sentences_lengthT;
      for( uint32_t i = 0; i < utterance_sentences_length; i++){
      offset += this->st_utterance_sentences.deserialize(inbuffer + offset);
        memcpy( &(this->utterance_sentences[i]), &(this->st_utterance_sentences), sizeof(strawberry_ros_msgs::DialogSentence));
      }
      uint32_t length_language_code;
      arrToVar(length_language_code, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_language_code; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_language_code-1]=0;
      this->language_code = (char *)(inbuffer + offset-1);
      offset += length_language_code;
      uint32_t length_fulfillment_text;
      arrToVar(length_fulfillment_text, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_fulfillment_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_fulfillment_text-1]=0;
      this->fulfillment_text = (char *)(inbuffer + offset-1);
      offset += length_fulfillment_text;
      uint32_t fulfillment_messages_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fulfillment_messages_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fulfillment_messages_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fulfillment_messages_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fulfillment_messages_length);
      if(fulfillment_messages_lengthT > fulfillment_messages_length)
        this->fulfillment_messages = (char**)realloc(this->fulfillment_messages, fulfillment_messages_lengthT * sizeof(char*));
      fulfillment_messages_length = fulfillment_messages_lengthT;
      for( uint32_t i = 0; i < fulfillment_messages_length; i++){
      uint32_t length_st_fulfillment_messages;
      arrToVar(length_st_fulfillment_messages, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_fulfillment_messages; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_fulfillment_messages-1]=0;
      this->st_fulfillment_messages = (char *)(inbuffer + offset-1);
      offset += length_st_fulfillment_messages;
        memcpy( &(this->fulfillment_messages[i]), &(this->st_fulfillment_messages), sizeof(char*));
      }
      uint32_t fulfillment_sentences_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fulfillment_sentences_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fulfillment_sentences_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fulfillment_sentences_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fulfillment_sentences_length);
      if(fulfillment_sentences_lengthT > fulfillment_sentences_length)
        this->fulfillment_sentences = (strawberry_ros_msgs::DialogSentence*)realloc(this->fulfillment_sentences, fulfillment_sentences_lengthT * sizeof(strawberry_ros_msgs::DialogSentence));
      fulfillment_sentences_length = fulfillment_sentences_lengthT;
      for( uint32_t i = 0; i < fulfillment_sentences_length; i++){
      offset += this->st_fulfillment_sentences.deserialize(inbuffer + offset);
        memcpy( &(this->fulfillment_sentences[i]), &(this->st_fulfillment_sentences), sizeof(strawberry_ros_msgs::DialogSentence));
      }
      uint32_t length_dialogue_act;
      arrToVar(length_dialogue_act, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_dialogue_act; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_dialogue_act-1]=0;
      this->dialogue_act = (char *)(inbuffer + offset-1);
      offset += length_dialogue_act;
      uint32_t length_topic;
      arrToVar(length_topic, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic-1]=0;
      this->topic = (char *)(inbuffer + offset-1);
      offset += length_topic;
      uint32_t length_subtopic;
      arrToVar(length_subtopic, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_subtopic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_subtopic-1]=0;
      this->subtopic = (char *)(inbuffer + offset-1);
      offset += length_subtopic;
      uint32_t length_question;
      arrToVar(length_question, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_question; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_question-1]=0;
      this->question = (char *)(inbuffer + offset-1);
      offset += length_question;
      union {
        bool real;
        uint8_t base;
      } u_conversation_finished;
      u_conversation_finished.base = 0;
      u_conversation_finished.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->conversation_finished = u_conversation_finished.real;
      offset += sizeof(this->conversation_finished);
      this->suggested_routine_id =  ((uint32_t) (*(inbuffer + offset)));
      this->suggested_routine_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->suggested_routine_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->suggested_routine_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->suggested_routine_id);
      offset += this->slu_result.deserialize(inbuffer + offset);
      offset += this->sentiment_results.deserialize(inbuffer + offset);
      offset += this->utterance_emotion.deserialize(inbuffer + offset);
      offset += this->fulfillment_emotion.deserialize(inbuffer + offset);
      uint32_t slots_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      slots_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      slots_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      slots_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->slots_length);
      if(slots_lengthT > slots_length)
        this->slots = (strawberry_ros_msgs::DialogSlot*)realloc(this->slots, slots_lengthT * sizeof(strawberry_ros_msgs::DialogSlot));
      slots_length = slots_lengthT;
      for( uint32_t i = 0; i < slots_length; i++){
      offset += this->st_slots.deserialize(inbuffer + offset);
        memcpy( &(this->slots[i]), &(this->st_slots), sizeof(strawberry_ros_msgs::DialogSlot));
      }
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/DialogResult"; };
    virtual const char * getMD5() override { return "4cd4d0e32ef67fe06679af9051c9c2df"; };

  };

}
#endif
