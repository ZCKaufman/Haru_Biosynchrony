#ifndef _ROS_SERVICE_MarkerVisual_h
#define _ROS_SERVICE_MarkerVisual_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/ColorRGBA.h"
#include "geometry_msgs/Vector3.h"

namespace idmind_tabletop_msgs
{

static const char MARKERVISUAL[] = "idmind_tabletop_msgs/MarkerVisual";

  class MarkerVisualRequest : public ros::Msg
  {
    public:
      typedef std_msgs::ColorRGBA _color_type;
      _color_type color;
      typedef geometry_msgs::Vector3 _scale_type;
      _scale_type scale;

    MarkerVisualRequest():
      color(),
      scale()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->color.serialize(outbuffer + offset);
      offset += this->scale.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->color.deserialize(inbuffer + offset);
      offset += this->scale.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return MARKERVISUAL; };
    virtual const char * getMD5() override { return "66c0a0fbdc47f42ae5a4916e8b64c97a"; };

  };

  class MarkerVisualResponse : public ros::Msg
  {
    public:

    MarkerVisualResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return MARKERVISUAL; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class MarkerVisual {
    public:
    typedef MarkerVisualRequest Request;
    typedef MarkerVisualResponse Response;
  };

}
#endif
