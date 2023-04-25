#ifndef _ROS_strawberry_ros_msgs_Person_h
#define _ROS_strawberry_ros_msgs_Person_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/Face.h"
#include "strawberry_ros_msgs/Skeleton.h"
#include "strawberry_ros_msgs/Hand.h"
#include "strawberry_ros_msgs/Speech.h"

namespace strawberry_ros_msgs
{

  class Person : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef strawberry_ros_msgs::Face _face_type;
      _face_type face;
      typedef strawberry_ros_msgs::Skeleton _skeleton_type;
      _skeleton_type skeleton;
      typedef strawberry_ros_msgs::Hand _right_hand_type;
      _right_hand_type right_hand;
      typedef strawberry_ros_msgs::Hand _left_hand_type;
      _left_hand_type left_hand;
      typedef strawberry_ros_msgs::Speech _speech_type;
      _speech_type speech;

    Person():
      id(0),
      face(),
      skeleton(),
      right_hand(),
      left_hand(),
      speech()
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
      offset += this->face.serialize(outbuffer + offset);
      offset += this->skeleton.serialize(outbuffer + offset);
      offset += this->right_hand.serialize(outbuffer + offset);
      offset += this->left_hand.serialize(outbuffer + offset);
      offset += this->speech.serialize(outbuffer + offset);
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
      offset += this->face.deserialize(inbuffer + offset);
      offset += this->skeleton.deserialize(inbuffer + offset);
      offset += this->right_hand.deserialize(inbuffer + offset);
      offset += this->left_hand.deserialize(inbuffer + offset);
      offset += this->speech.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/Person"; };
    virtual const char * getMD5() override { return "9ccab510da3be227895d33d7968dd87a"; };

  };

}
#endif
