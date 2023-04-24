#ifndef _ROS_strawberry_ros_msgs_DialogSentimentResult_h
#define _ROS_strawberry_ros_msgs_DialogSentimentResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "strawberry_ros_msgs/SentimentClassification.h"

namespace strawberry_ros_msgs
{

  class DialogSentimentResult : public ros::Msg
  {
    public:
      typedef strawberry_ros_msgs::SentimentClassification _utterance_sentiment_type;
      _utterance_sentiment_type utterance_sentiment;
      typedef strawberry_ros_msgs::SentimentClassification _fulfillment_sentiment_type;
      _fulfillment_sentiment_type fulfillment_sentiment;
      typedef strawberry_ros_msgs::SentimentClassification _avg_utterance_sentiment_type;
      _avg_utterance_sentiment_type avg_utterance_sentiment;
      typedef strawberry_ros_msgs::SentimentClassification _avg_fulfillment_sentiment_type;
      _avg_fulfillment_sentiment_type avg_fulfillment_sentiment;

    DialogSentimentResult():
      utterance_sentiment(),
      fulfillment_sentiment(),
      avg_utterance_sentiment(),
      avg_fulfillment_sentiment()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->utterance_sentiment.serialize(outbuffer + offset);
      offset += this->fulfillment_sentiment.serialize(outbuffer + offset);
      offset += this->avg_utterance_sentiment.serialize(outbuffer + offset);
      offset += this->avg_fulfillment_sentiment.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->utterance_sentiment.deserialize(inbuffer + offset);
      offset += this->fulfillment_sentiment.deserialize(inbuffer + offset);
      offset += this->avg_utterance_sentiment.deserialize(inbuffer + offset);
      offset += this->avg_fulfillment_sentiment.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "strawberry_ros_msgs/DialogSentimentResult"; };
    virtual const char * getMD5() override { return "7bea4cf3959ad7f2e5bb6cecbbf7b23c"; };

  };

}
#endif
