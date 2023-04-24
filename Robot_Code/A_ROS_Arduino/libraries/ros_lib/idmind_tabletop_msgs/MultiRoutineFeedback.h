#ifndef _ROS_idmind_tabletop_msgs_MultiRoutineFeedback_h
#define _ROS_idmind_tabletop_msgs_MultiRoutineFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace idmind_tabletop_msgs
{

  class MultiRoutineFeedback : public ros::Msg
  {
    public:
      typedef uint32_t _id_type;
      _id_type id;
      typedef float _progress_type;
      _progress_type progress;
      typedef const char* _routine_list_type;
      _routine_list_type routine_list;

    MultiRoutineFeedback():
      id(0),
      progress(0),
      routine_list("")
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
      offset += serializeAvrFloat64(outbuffer + offset, this->progress);
      uint32_t length_routine_list = strlen(this->routine_list);
      varToArr(outbuffer + offset, length_routine_list);
      offset += 4;
      memcpy(outbuffer + offset, this->routine_list, length_routine_list);
      offset += length_routine_list;
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->progress));
      uint32_t length_routine_list;
      arrToVar(length_routine_list, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_routine_list; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_routine_list-1]=0;
      this->routine_list = (char *)(inbuffer + offset-1);
      offset += length_routine_list;
     return offset;
    }

    virtual const char * getType() override { return "idmind_tabletop_msgs/MultiRoutineFeedback"; };
    virtual const char * getMD5() override { return "25a01b93adbc14152bb8473e3724e879"; };

  };

}
#endif
