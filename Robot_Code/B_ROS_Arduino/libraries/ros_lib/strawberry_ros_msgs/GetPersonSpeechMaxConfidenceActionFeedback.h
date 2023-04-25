#ifndef _ROS_strawberry_ros_msgs_GetPersonSpeechMaxConfidenceActionFeedback_h
#define _ROS_strawberry_ros_msgs_GetPersonSpeechMaxConfidenceActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "strawberry_ros_msgs/GetPersonSpeechMaxConfidenceFeedback.h"

namespace strawberry_ros_msgs
{

  class GetPersonSpeechMaxConfidenceActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef strawberry_ros_msgs::GetPersonSpeechMaxConfidenceFeedback _feedback_type;
      _feedback_type feedback;

    GetPersonSpeechMaxConfidenceActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/GetPersonSpeechMaxConfidenceActionFeedback"; };
    virtual const char * getMD5() override { return "e3bb17b7fceb63a01804ed3137b6f5de"; };

  };

}
#endif
