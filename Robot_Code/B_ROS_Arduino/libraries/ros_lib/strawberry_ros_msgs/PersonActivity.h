#ifndef _ROS_strawberry_ros_msgs_PersonActivity_h
#define _ROS_strawberry_ros_msgs_PersonActivity_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace strawberry_ros_msgs
{

  class PersonActivity : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef const char* _name_type;
      _name_type name;
      typedef geometry_msgs::Point _position_type;
      _position_type position;
      typedef const char* _body_gesture_type;
      _body_gesture_type body_gesture;
      typedef float _body_gesture_confidence_type;
      _body_gesture_confidence_type body_gesture_confidence;
      typedef const char* _face_emotion_type;
      _face_emotion_type face_emotion;
      typedef float _face_emotion_confidence_type;
      _face_emotion_confidence_type face_emotion_confidence;
      typedef geometry_msgs::Point _face_direction_type;
      _face_direction_type face_direction;
      typedef geometry_msgs::Point _body_direction_type;
      _body_direction_type body_direction;
      typedef geometry_msgs::Point _right_hand_direction_type;
      _right_hand_direction_type right_hand_direction;
      typedef geometry_msgs::Point _left_hand_direction_type;
      _left_hand_direction_type left_hand_direction;
      typedef const char* _looking_at_type;
      _looking_at_type looking_at;
      typedef int32_t _looking_at_id_type;
      _looking_at_id_type looking_at_id;
      typedef const char* _r_pointing_to_type;
      _r_pointing_to_type r_pointing_to;
      typedef int32_t _r_pointing_to_id_type;
      _r_pointing_to_id_type r_pointing_to_id;
      typedef const char* _l_pointing_to_type;
      _l_pointing_to_type l_pointing_to;
      typedef int32_t _l_pointing_to_id_type;
      _l_pointing_to_id_type l_pointing_to_id;

    PersonActivity():
      id(0),
      name(""),
      position(),
      body_gesture(""),
      body_gesture_confidence(0),
      face_emotion(""),
      face_emotion_confidence(0),
      face_direction(),
      body_direction(),
      right_hand_direction(),
      left_hand_direction(),
      looking_at(""),
      looking_at_id(0),
      r_pointing_to(""),
      r_pointing_to_id(0),
      l_pointing_to(""),
      l_pointing_to_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id);
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      offset += this->position.serialize(outbuffer + offset);
      uint32_t length_body_gesture = strlen(this->body_gesture);
      varToArr(outbuffer + offset, length_body_gesture);
      offset += 4;
      memcpy(outbuffer + offset, this->body_gesture, length_body_gesture);
      offset += length_body_gesture;
      union {
        float real;
        uint32_t base;
      } u_body_gesture_confidence;
      u_body_gesture_confidence.real = this->body_gesture_confidence;
      *(outbuffer + offset + 0) = (u_body_gesture_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_body_gesture_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_body_gesture_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_body_gesture_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->body_gesture_confidence);
      uint32_t length_face_emotion = strlen(this->face_emotion);
      varToArr(outbuffer + offset, length_face_emotion);
      offset += 4;
      memcpy(outbuffer + offset, this->face_emotion, length_face_emotion);
      offset += length_face_emotion;
      union {
        float real;
        uint32_t base;
      } u_face_emotion_confidence;
      u_face_emotion_confidence.real = this->face_emotion_confidence;
      *(outbuffer + offset + 0) = (u_face_emotion_confidence.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_face_emotion_confidence.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_face_emotion_confidence.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_face_emotion_confidence.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->face_emotion_confidence);
      offset += this->face_direction.serialize(outbuffer + offset);
      offset += this->body_direction.serialize(outbuffer + offset);
      offset += this->right_hand_direction.serialize(outbuffer + offset);
      offset += this->left_hand_direction.serialize(outbuffer + offset);
      uint32_t length_looking_at = strlen(this->looking_at);
      varToArr(outbuffer + offset, length_looking_at);
      offset += 4;
      memcpy(outbuffer + offset, this->looking_at, length_looking_at);
      offset += length_looking_at;
      union {
        int32_t real;
        uint32_t base;
      } u_looking_at_id;
      u_looking_at_id.real = this->looking_at_id;
      *(outbuffer + offset + 0) = (u_looking_at_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_looking_at_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_looking_at_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_looking_at_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->looking_at_id);
      uint32_t length_r_pointing_to = strlen(this->r_pointing_to);
      varToArr(outbuffer + offset, length_r_pointing_to);
      offset += 4;
      memcpy(outbuffer + offset, this->r_pointing_to, length_r_pointing_to);
      offset += length_r_pointing_to;
      union {
        int32_t real;
        uint32_t base;
      } u_r_pointing_to_id;
      u_r_pointing_to_id.real = this->r_pointing_to_id;
      *(outbuffer + offset + 0) = (u_r_pointing_to_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_r_pointing_to_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_r_pointing_to_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_r_pointing_to_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->r_pointing_to_id);
      uint32_t length_l_pointing_to = strlen(this->l_pointing_to);
      varToArr(outbuffer + offset, length_l_pointing_to);
      offset += 4;
      memcpy(outbuffer + offset, this->l_pointing_to, length_l_pointing_to);
      offset += length_l_pointing_to;
      union {
        int32_t real;
        uint32_t base;
      } u_l_pointing_to_id;
      u_l_pointing_to_id.real = this->l_pointing_to_id;
      *(outbuffer + offset + 0) = (u_l_pointing_to_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_l_pointing_to_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_l_pointing_to_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_l_pointing_to_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->l_pointing_to_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->id =  ((uint32_t) (*(inbuffer + offset)));
      this->id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->id);
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += this->position.deserialize(inbuffer + offset);
      uint32_t length_body_gesture;
      arrToVar(length_body_gesture, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_body_gesture; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_body_gesture-1]=0;
      this->body_gesture = (char *)(inbuffer + offset-1);
      offset += length_body_gesture;
      union {
        float real;
        uint32_t base;
      } u_body_gesture_confidence;
      u_body_gesture_confidence.base = 0;
      u_body_gesture_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_body_gesture_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_body_gesture_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_body_gesture_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->body_gesture_confidence = u_body_gesture_confidence.real;
      offset += sizeof(this->body_gesture_confidence);
      uint32_t length_face_emotion;
      arrToVar(length_face_emotion, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_face_emotion; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_face_emotion-1]=0;
      this->face_emotion = (char *)(inbuffer + offset-1);
      offset += length_face_emotion;
      union {
        float real;
        uint32_t base;
      } u_face_emotion_confidence;
      u_face_emotion_confidence.base = 0;
      u_face_emotion_confidence.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_face_emotion_confidence.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_face_emotion_confidence.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_face_emotion_confidence.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->face_emotion_confidence = u_face_emotion_confidence.real;
      offset += sizeof(this->face_emotion_confidence);
      offset += this->face_direction.deserialize(inbuffer + offset);
      offset += this->body_direction.deserialize(inbuffer + offset);
      offset += this->right_hand_direction.deserialize(inbuffer + offset);
      offset += this->left_hand_direction.deserialize(inbuffer + offset);
      uint32_t length_looking_at;
      arrToVar(length_looking_at, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_looking_at; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_looking_at-1]=0;
      this->looking_at = (char *)(inbuffer + offset-1);
      offset += length_looking_at;
      union {
        int32_t real;
        uint32_t base;
      } u_looking_at_id;
      u_looking_at_id.base = 0;
      u_looking_at_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_looking_at_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_looking_at_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_looking_at_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->looking_at_id = u_looking_at_id.real;
      offset += sizeof(this->looking_at_id);
      uint32_t length_r_pointing_to;
      arrToVar(length_r_pointing_to, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_r_pointing_to; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_r_pointing_to-1]=0;
      this->r_pointing_to = (char *)(inbuffer + offset-1);
      offset += length_r_pointing_to;
      union {
        int32_t real;
        uint32_t base;
      } u_r_pointing_to_id;
      u_r_pointing_to_id.base = 0;
      u_r_pointing_to_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_r_pointing_to_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_r_pointing_to_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_r_pointing_to_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->r_pointing_to_id = u_r_pointing_to_id.real;
      offset += sizeof(this->r_pointing_to_id);
      uint32_t length_l_pointing_to;
      arrToVar(length_l_pointing_to, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_l_pointing_to; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_l_pointing_to-1]=0;
      this->l_pointing_to = (char *)(inbuffer + offset-1);
      offset += length_l_pointing_to;
      union {
        int32_t real;
        uint32_t base;
      } u_l_pointing_to_id;
      u_l_pointing_to_id.base = 0;
      u_l_pointing_to_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_l_pointing_to_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_l_pointing_to_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_l_pointing_to_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->l_pointing_to_id = u_l_pointing_to_id.real;
      offset += sizeof(this->l_pointing_to_id);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/PersonActivity"; };
    virtual const char * getMD5() override { return "8cca10d3ff15ef4f6a7f8ea00ab77c8e"; };

  };

}
#endif
