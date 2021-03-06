// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from libunity.djinni

#import "DBQrCodeRecord+Private.h"
#import "DJIMarshal+Private.h"
#include <cassert>

namespace djinni_generated {

auto QrCodeRecord::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::I32::toCpp(obj.width),
            ::djinni::Binary::toCpp(obj.pixelData)};
}

auto QrCodeRecord::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[DBQrCodeRecord alloc] initWithWidth:(::djinni::I32::fromCpp(cpp.width))
                                       pixelData:(::djinni::Binary::fromCpp(cpp.pixel_data))];
}

}  // namespace djinni_generated
