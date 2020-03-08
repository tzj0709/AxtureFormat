﻿/*!
 *  @brief     qss文件格式输出
 *  @details
 *  @author    wey
 *  @version   1.0
 *  @date      2020.02.10
 *  @warning
 *  @copyright NanJing RenGu.
 */
#ifndef QSSPARSEMETHOD_H
#define QSSPARSEMETHOD_H

#include <QStringList>

#include "../../util/fileutils.h"
#include "../../css/cssstruct.h"

namespace RQt{

class QSSParseMethod : public RTextParseMethod
{
public:
    QSSParseMethod();

    void setCommonStyle(const CSS::CssMap& globalCss,const CSS::CssMap& pageCss);

    bool  startSave(RTextFile * file) override;

private:
    CSS::CssMap m_globalCss;
    CSS::CssMap m_pageCss;
};

} //namespace RQt

#endif // QSSPARSEMETHOD_H