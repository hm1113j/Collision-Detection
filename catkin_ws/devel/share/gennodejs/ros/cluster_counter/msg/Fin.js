// Auto-generated. Do not edit!

// (in-package cluster_counter.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Fin {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.num = null;
      this.aveD = null;
      this.minD = null;
      this.angle = null;
      this.size = null;
    }
    else {
      if (initObj.hasOwnProperty('num')) {
        this.num = initObj.num
      }
      else {
        this.num = 0;
      }
      if (initObj.hasOwnProperty('aveD')) {
        this.aveD = initObj.aveD
      }
      else {
        this.aveD = [];
      }
      if (initObj.hasOwnProperty('minD')) {
        this.minD = initObj.minD
      }
      else {
        this.minD = [];
      }
      if (initObj.hasOwnProperty('angle')) {
        this.angle = initObj.angle
      }
      else {
        this.angle = [];
      }
      if (initObj.hasOwnProperty('size')) {
        this.size = initObj.size
      }
      else {
        this.size = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Fin
    // Serialize message field [num]
    bufferOffset = _serializer.int64(obj.num, buffer, bufferOffset);
    // Serialize message field [aveD]
    bufferOffset = _arraySerializer.float64(obj.aveD, buffer, bufferOffset, null);
    // Serialize message field [minD]
    bufferOffset = _arraySerializer.float64(obj.minD, buffer, bufferOffset, null);
    // Serialize message field [angle]
    bufferOffset = _arraySerializer.float64(obj.angle, buffer, bufferOffset, null);
    // Serialize message field [size]
    bufferOffset = _arraySerializer.float64(obj.size, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Fin
    let len;
    let data = new Fin(null);
    // Deserialize message field [num]
    data.num = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [aveD]
    data.aveD = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [minD]
    data.minD = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [angle]
    data.angle = _arrayDeserializer.float64(buffer, bufferOffset, null)
    // Deserialize message field [size]
    data.size = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 8 * object.aveD.length;
    length += 8 * object.minD.length;
    length += 8 * object.angle.length;
    length += 8 * object.size.length;
    return length + 24;
  }

  static datatype() {
    // Returns string type for a message object
    return 'cluster_counter/Fin';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e9d0a7c59b5482a4d7136307a7022f4a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int64 num
    float64[]  aveD
    float64[]  minD
    float64[]  angle
    float64[]  size
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Fin(null);
    if (msg.num !== undefined) {
      resolved.num = msg.num;
    }
    else {
      resolved.num = 0
    }

    if (msg.aveD !== undefined) {
      resolved.aveD = msg.aveD;
    }
    else {
      resolved.aveD = []
    }

    if (msg.minD !== undefined) {
      resolved.minD = msg.minD;
    }
    else {
      resolved.minD = []
    }

    if (msg.angle !== undefined) {
      resolved.angle = msg.angle;
    }
    else {
      resolved.angle = []
    }

    if (msg.size !== undefined) {
      resolved.size = msg.size;
    }
    else {
      resolved.size = []
    }

    return resolved;
    }
};

module.exports = Fin;
