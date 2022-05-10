import inet.common.INETDefs;
import inet.common.packet.chunk.Chunk;
import KOPSMsg;
import KInternalMsg;

class INATypeMsg extends inet::FieldsChunk {
    int senderID;
    int msgKind;
}

class INAUserMsgHeader extends inet::FieldsChunk{
 	int ptrType; 
}

class INAUpdateMsg extends inet::FieldsChunk {
    int16_t neighborCount;
    int neighborID[];
    bool ack[];
    string macAddress;
}

class INAUserMsg_KDataMsg extends inet::FieldsChunk
{
    KDataMsg data;
} 

class INAUserMsg_KFeedbackMsg extends inet::FieldsChunk
{
 	KFeedbackMsg data;   
}

class INAUserMsg_KSummaryVectorMsg extends inet::FieldsChunk
{
 	KSummaryVectorMsg data;   
}

class INAUserMsg_KDataRequestMsg extends inet::FieldsChunk
{
	KDataRequestMsg data;   
}

class INAUserMsg_KReactionMsg extends inet::FieldsChunk
{
 	KReactionMsg data;   
}

class INAUserMsg_KDPtableRequestMsg extends inet::FieldsChunk
{
 	KDPtableRequestMsg data;  
}

class INAUserMsg_KDPtableDataMsg extends inet::FieldsChunk
{
 	KDPtableDataMsg data;  
}
