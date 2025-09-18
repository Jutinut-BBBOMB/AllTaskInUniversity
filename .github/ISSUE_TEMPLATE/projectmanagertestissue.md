---
name: ProjectManagerTestIssue
about: This Template is example for create template issue
title: "[PM]"
labels: PM
assignees: Jutinut-BBBOMB

---

"📅 Project Management Task"
description: "งานสำหรับการวางแผน / ติดตามความคืบหน้า"
title: "[PM] <ชื่อ Task>"
labels: ["PM", "planning"]
body:
  - type: textarea
    id: objective
    attributes:
      label: 🎯 เป้าหมายของงาน
      description: ระบุว่าต้องการทำอะไร (เช่น วางแผน Sprint, ประชุมสรุป)
      placeholder: "เช่น จัดประชุมกับทีมเพื่ออัปเดตความคืบหน้า"
  - type: textarea
    id: deliverable
    attributes:
      label: 📦 ผลลัพธ์ที่คาดหวัง
      description: ระบุเอกสาร/ผลลัพธ์ที่จะส่งมอบ
      placeholder: "เช่น Gantt Chart v1.0"
  - type: input
    id: due_date
    attributes:
      label: 🗓️ วันครบกำหนด
      description: วันที่ต้องทำงานเสร็จ
      placeholder: "YYYY-MM-DD"
