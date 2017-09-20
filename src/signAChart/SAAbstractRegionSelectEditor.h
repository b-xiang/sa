#ifndef SAABSTRACTREGIONSELECTEDITOR_H
#define SAABSTRACTREGIONSELECTEDITOR_H
#include "SAChartGlobals.h"
#include "SAAbstractPlotEditor.h"
#include <QPainterPath>
class QwtPlotShapeItem;
class SA_CHART_EXPORT SAAbstractRegionSelectEditor : public SAAbstractPlotEditor
{
    Q_OBJECT
    Q_ENUMS(SelectionMode)
public:
    SAAbstractRegionSelectEditor(QwtPlot* parent);
    ~SAAbstractRegionSelectEditor();
    enum SelectionMode
    {
        SingleSelection ///< 单选
        ,AdditionalSelection ///< 合并选区
        ,SubtractionSelection ///< 减去选区
        ,IntersectionSelection ///<  交集选区
    };
    virtual SelectionMode getSelectionMode() const;
    virtual void setSelectionMode(const SelectionMode &selectionMode);
    //获取选择的数据区域
    virtual QPainterPath getSelectRegion() const = 0;
    virtual void setSelectRegion(const QPainterPath& shape) = 0;
    //判断点是否在区域里 此算法频繁调用会耗时
    virtual bool isContains(const QPointF& p) const = 0;
    //判断是否显示选区
    virtual bool isRegionVisible() const = 0;
    //获取绑定的x轴
    int getXAxis() const;
    //获取绑定的y轴
    int getYAxis() const;
    //设置关联的坐标轴
    void setAxis(int xAxis,int yAxis);
    //屏幕坐标转换为数据坐标
    QPointF invTransform( const QPointF &pos ) const;
    //数据坐标转换为屏幕坐标
    QPointF transform( const QPointF &pos ) const;
    //把当前区域转换为其它轴系
    QPainterPath transformToOtherAxis(int axisX,int axisY);
private:
    SelectionMode m_selectionMode; ///< 选框类型
    int m_xAxis;
    int m_yAxis;
};

#endif // SAABSTRACTREGIONSELECTEDITOR_H
