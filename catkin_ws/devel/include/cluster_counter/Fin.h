// Generated by gencpp from file cluster_counter/Fin.msg
// DO NOT EDIT!


#ifndef CLUSTER_COUNTER_MESSAGE_FIN_H
#define CLUSTER_COUNTER_MESSAGE_FIN_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace cluster_counter
{
template <class ContainerAllocator>
struct Fin_
{
  typedef Fin_<ContainerAllocator> Type;

  Fin_()
    : num(0)
    , aveD()
    , minD()
    , angle()
    , size()  {
    }
  Fin_(const ContainerAllocator& _alloc)
    : num(0)
    , aveD(_alloc)
    , minD(_alloc)
    , angle(_alloc)
    , size(_alloc)  {
  (void)_alloc;
    }



   typedef int64_t _num_type;
  _num_type num;

   typedef std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> _aveD_type;
  _aveD_type aveD;

   typedef std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> _minD_type;
  _minD_type minD;

   typedef std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> _angle_type;
  _angle_type angle;

   typedef std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> _size_type;
  _size_type size;





  typedef boost::shared_ptr< ::cluster_counter::Fin_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cluster_counter::Fin_<ContainerAllocator> const> ConstPtr;

}; // struct Fin_

typedef ::cluster_counter::Fin_<std::allocator<void> > Fin;

typedef boost::shared_ptr< ::cluster_counter::Fin > FinPtr;
typedef boost::shared_ptr< ::cluster_counter::Fin const> FinConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cluster_counter::Fin_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cluster_counter::Fin_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::cluster_counter::Fin_<ContainerAllocator1> & lhs, const ::cluster_counter::Fin_<ContainerAllocator2> & rhs)
{
  return lhs.num == rhs.num &&
    lhs.aveD == rhs.aveD &&
    lhs.minD == rhs.minD &&
    lhs.angle == rhs.angle &&
    lhs.size == rhs.size;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::cluster_counter::Fin_<ContainerAllocator1> & lhs, const ::cluster_counter::Fin_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace cluster_counter

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::cluster_counter::Fin_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cluster_counter::Fin_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cluster_counter::Fin_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cluster_counter::Fin_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cluster_counter::Fin_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cluster_counter::Fin_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cluster_counter::Fin_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e9d0a7c59b5482a4d7136307a7022f4a";
  }

  static const char* value(const ::cluster_counter::Fin_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe9d0a7c59b5482a4ULL;
  static const uint64_t static_value2 = 0xd7136307a7022f4aULL;
};

template<class ContainerAllocator>
struct DataType< ::cluster_counter::Fin_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cluster_counter/Fin";
  }

  static const char* value(const ::cluster_counter::Fin_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cluster_counter::Fin_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int64 num\n"
"float64[]  aveD\n"
"float64[]  minD\n"
"float64[]  angle\n"
"float64[]  size\n"
;
  }

  static const char* value(const ::cluster_counter::Fin_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cluster_counter::Fin_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.num);
      stream.next(m.aveD);
      stream.next(m.minD);
      stream.next(m.angle);
      stream.next(m.size);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Fin_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cluster_counter::Fin_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cluster_counter::Fin_<ContainerAllocator>& v)
  {
    s << indent << "num: ";
    Printer<int64_t>::stream(s, indent + "  ", v.num);
    s << indent << "aveD[]" << std::endl;
    for (size_t i = 0; i < v.aveD.size(); ++i)
    {
      s << indent << "  aveD[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.aveD[i]);
    }
    s << indent << "minD[]" << std::endl;
    for (size_t i = 0; i < v.minD.size(); ++i)
    {
      s << indent << "  minD[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.minD[i]);
    }
    s << indent << "angle[]" << std::endl;
    for (size_t i = 0; i < v.angle.size(); ++i)
    {
      s << indent << "  angle[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.angle[i]);
    }
    s << indent << "size[]" << std::endl;
    for (size_t i = 0; i < v.size.size(); ++i)
    {
      s << indent << "  size[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.size[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // CLUSTER_COUNTER_MESSAGE_FIN_H
