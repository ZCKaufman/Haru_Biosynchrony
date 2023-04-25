#ifndef _ROS_strawberry_ros_msgs_Face_h
#define _ROS_strawberry_ros_msgs_Face_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/Name.h"
#include "strawberry_ros_msgs/BoundingBox.h"
#include "strawberry_ros_msgs/FaceEmotion.h"
#include "geometry_msgs/Pose2D.h"
#include "geometry_msgs/Quaternion.h"

namespace strawberry_ros_msgs
{

  class Face : public ros::Msg
  {
    public:
      typedef strawberry_ros_msgs::Name _name_type;
      _name_type name;
      typedef strawberry_ros_msgs::BoundingBox _bb_type;
      _bb_type bb;
      uint32_t emotions_length;
      typedef strawberry_ros_msgs::FaceEmotion _emotions_type;
      _emotions_type st_emotions;
      _emotions_type * emotions;
      uint32_t landmarks_length;
      typedef geometry_msgs::Pose2D _landmarks_type;
      _landmarks_type st_landmarks;
      _landmarks_type * landmarks;
      typedef geometry_msgs::Quaternion _rotation_type;
      _rotation_type rotation;
      typedef uint8_t _gender_type;
      _gender_type gender;
      typedef uint8_t _mask_type;
      _mask_type mask;
      enum { GENDER_UNKNOWN =  0 };
      enum { GENDER_MALE =  1 };
      enum { GENDER_FEMALE =  2 };
      enum { MASK_UNKNOWN =  0 };
      enum { MASK_YES =  1 };
      enum { MASK_NO =  2 };

    Face():
      name(),
      bb(),
      emotions_length(0), st_emotions(), emotions(nullptr),
      landmarks_length(0), st_landmarks(), landmarks(nullptr),
      rotation(),
      gender(0),
      mask(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->name.serialize(outbuffer + offset);
      offset += this->bb.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->emotions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->emotions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->emotions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->emotions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->emotions_length);
      for( uint32_t i = 0; i < emotions_length; i++){
      offset += this->emotions[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->landmarks_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->landmarks_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->landmarks_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->landmarks_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->landmarks_length);
      for( uint32_t i = 0; i < landmarks_length; i++){
      offset += this->landmarks[i].serialize(outbuffer + offset);
      }
      offset += this->rotation.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->gender >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gender);
      *(outbuffer + offset + 0) = (this->mask >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mask);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->name.deserialize(inbuffer + offset);
      offset += this->bb.deserialize(inbuffer + offset);
      uint32_t emotions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      emotions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      emotions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      emotions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->emotions_length);
      if(emotions_lengthT > emotions_length)
        this->emotions = (strawberry_ros_msgs::FaceEmotion*)realloc(this->emotions, emotions_lengthT * sizeof(strawberry_ros_msgs::FaceEmotion));
      emotions_length = emotions_lengthT;
      for( uint32_t i = 0; i < emotions_length; i++){
      offset += this->st_emotions.deserialize(inbuffer + offset);
        memcpy( &(this->emotions[i]), &(this->st_emotions), sizeof(strawberry_ros_msgs::FaceEmotion));
      }
      uint32_t landmarks_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      landmarks_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      landmarks_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      landmarks_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->landmarks_length);
      if(landmarks_lengthT > landmarks_length)
        this->landmarks = (geometry_msgs::Pose2D*)realloc(this->landmarks, landmarks_lengthT * sizeof(geometry_msgs::Pose2D));
      landmarks_length = landmarks_lengthT;
      for( uint32_t i = 0; i < landmarks_length; i++){
      offset += this->st_landmarks.deserialize(inbuffer + offset);
        memcpy( &(this->landmarks[i]), &(this->st_landmarks), sizeof(geometry_msgs::Pose2D));
      }
      offset += this->rotation.deserialize(inbuffer + offset);
      this->gender =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gender);
      this->mask =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mask);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/Face"; };
    virtual const char * getMD5() override { return "0a981e2932bfbd46b2ba0d7a81eb5ac3"; };

  };

}
#endif
