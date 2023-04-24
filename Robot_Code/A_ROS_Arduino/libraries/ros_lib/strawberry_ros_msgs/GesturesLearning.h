#ifndef _ROS_SERVICE_GesturesLearning_h
#define _ROS_SERVICE_GesturesLearning_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/UInt32.h"

namespace strawberry_ros_msgs
{

static const char GESTURESLEARNING[] = "strawberry_ros_msgs/GesturesLearning";

  class GesturesLearningRequest : public ros::Msg
  {
    public:
      typedef const char* _model_name_type;
      _model_name_type model_name;
      typedef const char* _dataset_save_path_type;
      _dataset_save_path_type dataset_save_path;
      typedef bool _load_model_after_train_type;
      _load_model_after_train_type load_model_after_train;
      typedef bool _use_auto_train_type;
      _use_auto_train_type use_auto_train;
      typedef std_msgs::UInt32 _auto_train_max_time_type;
      _auto_train_max_time_type auto_train_max_time;

    GesturesLearningRequest():
      model_name(""),
      dataset_save_path(""),
      load_model_after_train(0),
      use_auto_train(0),
      auto_train_max_time()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_model_name = strlen(this->model_name);
      varToArr(outbuffer + offset, length_model_name);
      offset += 4;
      memcpy(outbuffer + offset, this->model_name, length_model_name);
      offset += length_model_name;
      uint32_t length_dataset_save_path = strlen(this->dataset_save_path);
      varToArr(outbuffer + offset, length_dataset_save_path);
      offset += 4;
      memcpy(outbuffer + offset, this->dataset_save_path, length_dataset_save_path);
      offset += length_dataset_save_path;
      union {
        bool real;
        uint8_t base;
      } u_load_model_after_train;
      u_load_model_after_train.real = this->load_model_after_train;
      *(outbuffer + offset + 0) = (u_load_model_after_train.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->load_model_after_train);
      union {
        bool real;
        uint8_t base;
      } u_use_auto_train;
      u_use_auto_train.real = this->use_auto_train;
      *(outbuffer + offset + 0) = (u_use_auto_train.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_auto_train);
      offset += this->auto_train_max_time.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_model_name;
      arrToVar(length_model_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model_name-1]=0;
      this->model_name = (char *)(inbuffer + offset-1);
      offset += length_model_name;
      uint32_t length_dataset_save_path;
      arrToVar(length_dataset_save_path, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_dataset_save_path; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_dataset_save_path-1]=0;
      this->dataset_save_path = (char *)(inbuffer + offset-1);
      offset += length_dataset_save_path;
      union {
        bool real;
        uint8_t base;
      } u_load_model_after_train;
      u_load_model_after_train.base = 0;
      u_load_model_after_train.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->load_model_after_train = u_load_model_after_train.real;
      offset += sizeof(this->load_model_after_train);
      union {
        bool real;
        uint8_t base;
      } u_use_auto_train;
      u_use_auto_train.base = 0;
      u_use_auto_train.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_auto_train = u_use_auto_train.real;
      offset += sizeof(this->use_auto_train);
      offset += this->auto_train_max_time.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return GESTURESLEARNING; };
    virtual const char * getMD5() override { return "936afa21186f4bafbb9a8b2dd22bf134"; };

  };

  class GesturesLearningResponse : public ros::Msg
  {
    public:

    GesturesLearningResponse()
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

    virtual const char * getType() override { return GESTURESLEARNING; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GesturesLearning {
    public:
    typedef GesturesLearningRequest Request;
    typedef GesturesLearningResponse Response;
  };

}
#endif
