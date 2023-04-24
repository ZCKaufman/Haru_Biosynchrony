#ifndef _ROS_idmind_tabletop_msgs_TFSpeed_h
#define _ROS_idmind_tabletop_msgs_TFSpeed_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class TFSpeed : public ros::Msg
  {
    public:
      typedef uint32_t _person_id_type;
      _person_id_type person_id;
      typedef const char* _tf_frame_id_type;
      _tf_frame_id_type tf_frame_id;
      typedef float _speed_type;
      _speed_type speed;

    TFSpeed():
      person_id(0),
      tf_frame_id(""),
      speed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->person_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->person_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->person_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->person_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->person_id);
      uint32_t length_tf_frame_id = strlen(this->tf_frame_id);
      varToArr(outbuffer + offset, length_tf_frame_id);
      offset += 4;
      memcpy(outbuffer + offset, this->tf_frame_id, length_tf_frame_id);
      offset += length_tf_frame_id;
      offset += serializeAvrFloat64(outbuffer + offset, this->speed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->person_id =  ((uint32_t) (*(inbuffer + offset)));
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->person_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->person_id);
      uint32_t length_tf_frame_id;
      arrToVar(length_tf_frame_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_tf_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_tf_frame_id-1]=0;
      this->tf_frame_id = (char *)(inbuffer + offset-1);
      offset += length_tf_frame_id;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->speed));
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/TFSpeed"; };
    virtual const char * getMD5() override { return "56a286f848a4835e40e9ad367ed88714"; };

  };

}
#endif
