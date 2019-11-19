#ifndef HEADER_INTERFACE_MSG
#define HEADER_INTERFACE_MSG

#include "CommonType.h"

namespace hudp {
    enum flag_type {
        msg_has_changed   = 0x0001,   // message has be change, need serialize again
        msg_is_in_timer   = 0x0002,   // message has be setted in timer
        msg_is_only_ack   = 0x0004,   // message is only with ack
    };

    // msg base class.
    class CMsg
    {
    public:
        CMsg() {}
        virtual ~CMsg() {}
        // clear all member 
        virtual void Clear() = 0;
        // // clear member which about ack
        virtual void ClearAck() = 0;

        virtual void SetId(const uint16_t& id) = 0;
        virtual uint16_t GetId() = 0;

        // add send delay time
        virtual void AddSendDelay() = 0;

        // translate user flag to hudp flag.
        virtual void TranslateFlag() = 0;
        virtual void SetHeaderFlag(uint16_t flag) = 0;
        virtual uint16_t GetHeaderFlag() = 0;

        virtual void SetFlag(uint16_t flag) = 0;
        virtual uint16_t GetFlag() = 0;

        virtual void SetHandle(const Handle& handle) = 0;
        virtual const Handle& GetHandle() = 0;
        
        virtual void SetBody(const std::string& body) = 0;
        virtual std::string& GetBody() = 0;

        // ack about
        virtual void SetAck(int16_t flag, std::vector<uint16_t>& ack_vec, bool continuity) = 0;
        virtual void GetAck(int16_t flag, std::vector<uint16_t>& ack_vec) = 0;

        // get buffer that is serialized
        virtual std::string GetSerializeBuffer() = 0;
        virtual bool InitWithBuffer() = 0;

        // next point about
        virtual void SetNext(CMsg* msg) = 0;
        virtual CMsg* GetNext() = 0;
    };
}
#endif